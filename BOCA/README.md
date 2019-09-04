# Corretor Local

Para utilizar o corretor local basta utilizar o comando

```bash
python3 run.py <sua_solucao.c> <rotulo_do_problema>
```

Em que `<sua_solucao.c>` é o seu código e `<rotulo_do_problema>` é o rótulo do problema, geralmente uma sequência de letras maíúsculas (Ex: BA).

O corretor local então gerara as entradas e saídas e comparará as saídas do seu programa com as saídas esperadas, dado um veredito para cada uma. Os possíveis vereditos são:

- CE: erro de compilação. Seu programa não compila.
- WA: reposta errada.
- AC: resposta correta.
- PE: erro de apresentação. Sua resposta não segue o formato correto.
- FAIL: tem algo errado com os arquivos do professor.]

Ao final da execução do seu programa, existe uma pasta `tmp` contendo as saídas do seu programa para cada caso de teste. Você pode compará-las com as saídas esperadas de cada problema para debugar seu código.

Dentro de cada pasta de problema você irá encontrar uma pasta `src` que possui a solução esperada. Após rodar o corretor local, também existirão as pastas `input` e `output`, que representam, respectivamente, os casos de teste e as saídas esperadas.

**Observação**: você deverá estar na pasta do script `run.py` para que o corretor funcine.

