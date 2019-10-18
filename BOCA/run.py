
import sys
import os
import shutil
import subprocess
import time

CPP_COMPILER = "g++"
CPP_FLAGS = "-O2 -Wall"
C_COMPILER = "gcc"
C_FLAGS = "-O2 -Wall"
C_LD_FLAGS = '-lm'
CPP_LD_FLAGS = '-lm'
INCLUDE = 'include'
INCLUDE_CMD = '-I'+INCLUDE


if len(sys.argv) != 3:
    print('Usage: ./run.py <source_file.c> <problem_name>')
    print('Example: ./run.py solution.c A')
    exit(0)

root_folder = os.getcwd()
source_file = sys.argv[1]
problem_folder = sys.argv[2]
tmp_folder = 'tmp'

if not os.path.isfile(source_file):
    print(source_file, ' does not exists.')
    exit(0)

if not os.path.isdir(problem_folder):
    print(problem_folder, ' does not exists.')
    exit(0)

print('- Creating empty test/run directory')
if os.path.isdir('tmp'):
    shutil.rmtree('tmp')
os.mkdir('tmp')


bin_folder = os.path.join(problem_folder, 'bin')
if not os.path.isdir(os.path.join(bin_folder)):
    os.mkdir(bin_folder)

generator_src = os.path.join(*[problem_folder, 'src', 'generator.cpp'])
checker_src = os.path.join(*[problem_folder, 'src', 'checker.cpp'])
ac_src = os.path.join(*[problem_folder, 'src', 'ac.cpp'])


ac_binary = os.path.join(
    bin_folder, os.path.splitext(os.path.basename(ac_src))[0])

checker_binary = os.path.join(
    bin_folder, os.path.splitext(os.path.basename(checker_src))[0])

print('- Compiling generator')
command = " ".join([CPP_COMPILER, generator_src, CPP_FLAGS, INCLUDE_CMD, '-o',
                    os.path.join(bin_folder, os.path.splitext(os.path.basename(generator_src))[0]), CPP_LD_FLAGS])
print(command)
p = subprocess.run(command.split(' '),stdout=subprocess.PIPE,stderr=subprocess.PIPE)
if(p.returncode):
    print('Could not compile generator, contact Daniel Saad')
    exit(1)

print('- Compiling checker')
command = ' '.join([CPP_COMPILER, checker_src, CPP_FLAGS, INCLUDE_CMD, '-o',
                    checker_binary, CPP_LD_FLAGS])
print(command)
p = subprocess.run(command.split(' '),stdout=subprocess.PIPE,stderr=subprocess.PIPE)
if(p.returncode):
    print('Could not compile checker, contact Daniel Saad')
    exit(1)
print('- Compiling expected solution')
command = ' '.join([CPP_COMPILER, ac_src, CPP_FLAGS, INCLUDE_CMD, '-o',
                    ac_binary, CPP_LD_FLAGS])
print(command)
p = subprocess.run(command.split(' '),stdout=subprocess.PIPE,stderr=subprocess.PIPE)
if(p.returncode):
    print('Could not compile expected solution, contact Daniel Saad')
    exit(1)

print('- Generating tests for problem ', problem_folder)
input_folder = os.path.join(problem_folder, 'input')
os.makedirs(input_folder, exist_ok=True)
os.chdir(input_folder)
command = '../bin/generator'
p = subprocess.run(command.split(' '))
if(p.returncode):
    print('Could not generate tests, contact Daniel Saad')
    exit(1)
os.chdir(root_folder)

print('- Generating answers for problem ', problem_folder)
output_folder = os.path.join(problem_folder, 'output')
os.makedirs(output_folder, exist_ok=True)
input_files = [os.path.join(input_folder, f) for f in os.listdir(input_folder)]
input_files = sorted(input_files, key=lambda i: (len(i), i))
output_files = [os.path.join(output_folder, f)
                for f in os.listdir(input_folder)]
output_files = sorted(output_files, key=lambda i: (len(i), i))


for inf_f, ouf_f in zip(input_files, output_files):
    with open(inf_f, 'r') as inf, open(ouf_f, 'w') as ouf:
        p = subprocess.run([ac_binary], stdin=inf, stdout=ouf)
        if(p.returncode):
            print('Could not generate expected output, contact Daniel Saad')
            exit(1)

print('- Compiling user solution')
user_binary = os.path.join(tmp_folder, os.path.splitext(
    os.path.basename(source_file))[0])
command = ' '.join([C_COMPILER, source_file, C_FLAGS,
                    '-o', user_binary, C_LD_FLAGS])
print(command)
p = subprocess.run(command.split(' '))
if(p.returncode):
    print('CE: compilation failed')
    exit(0)

print('- Running user solutions')
print('Creating user output folder')
user_output = os.path.join(tmp_folder, 'output')
os.makedirs(user_output, exist_ok=True)
user_output_files = [os.path.join(
    user_output, os.path.basename(f)) for f in input_files]
user_output_files = sorted(user_output_files, key=lambda i: (len(i), i))
for inf_f, ouf_f in zip(input_files, user_output_files):
    with open(inf_f, 'r') as inf, open(ouf_f, 'w') as ouf:

        start = time.perf_counter()
        subprocess.run([user_binary], stdin=inf, stdout=ouf)
        end = time.perf_counter()
        print("Test case: ", os.path.basename(inf_f), end='. ')
        print("Time elapsed = {:.2f}".format(end-start))

print('- Checking user solution')

for (inf, ans, ouf) in zip(input_files, user_output_files, output_files):
    command = ' '.join([checker_binary, inf, ans, ouf])
    print(command)
    fname = os.path.basename(inf)
    p = subprocess.run(command.split(
        ' '), stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    checker_output = p.stderr.decode('utf-8')
    if(checker_output.startswith('ok')):
        print('Input', fname, ': AC')
    elif(checker_output.startswith('wrong answer')):
        print('Input', fname, ': WA')
    elif(checker_output.startswith('wrong output format')):
        print('Input', fname, ': PE')
    elif(checker_output.startswith('FAIL')):
        print('Input', fname,
              ': FAIL: maybe the jury solution or the checker are not correct. Contact Daniel Saad.')
        sys.exit(0)
