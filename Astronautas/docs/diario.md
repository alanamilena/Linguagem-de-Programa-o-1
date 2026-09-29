# Diário da atividade

Escreva com as suas palavras. Frases curtas bastam. Não cole a conversa inteira
com a IA. Cole só os pedidos que você enviou.

## Ambiente

- Versão do OpenCode (`opencode --version`): 1.18.31
- Modelo usado: Big Pickle (Free).

## Parte 1: antes de programar

- O que cada classe guarda: ![Desenho das classes](desenhos-das-classes-parte1.jpeg)
- O que acontece em `LANCAR_VOO`, em palavras: A Agencia procura o voo 10 e verifica se está planejado e se tem astronautas. Depois, verifica todos os astronautas: primeiro vivo, depois disponível. Se algum estiver morto ou indisponível, dá erro e para, sem embarcar ninguém. Morto vem primeiro porque um morto também está indisponível. Só depois de todos passarem na verificação, a Agencia manda todos embarcarem e muda o voo para em curso.
- Uma dúvida que eu tinha antes de começar: Fiquei bastante tempo para escrever os laços, tenho muita dificuldade nisso.

## Parte 1: uso de IA para entender algo

- O que perguntei (ou "não usei"): Tive dúvidas sobre como fazer o commit e enviar as alterações do projeto para o GitHub.
- O que aprendi: Aprendi a usar commit e push para enviar as alterações do VS Code para o GitHub.

## Primeiro contato: revisão sem editar

- As três melhorias que a IA sugeriu, em uma linha cada: usar const nos métodos que apenas fazem leitura; usar enum para representar os estados dos voos; reduzir a repetição de código no método listarVoos.
- A que escolhi e por quê: escolhi usar const nos métodos de leitura porque foi uma alteração simples de entender e não mudaria a lógica do programa.
- O que mudou no código, e se os seis testes continuaram passando:foram adicionados const aos 10 métodos de leitura das classes Astronauta e Voo. Os seis testes continuaram passando.
- O que entendi que não sabia antes:entendi que colocar const depois dos parâmetros de um método indica que aquele método não deve modificar os dados do objeto.

## Missão 1: LISTAR_ASTRONAUTAS e HISTORICO

- Primeira mensagem (o pedido do plano): pedi ao OpenCode para implementar os comandos LISTAR_ASTRONAUTAS e HISTORICO cpf, sem alterar os comandos existentes, e pedi que primeiro apresentasse o plano sem editar os arquivos.
- O plano que a IA apresentou, resumido: riar os métodos listarAstronautas() e historico(string cpf) na classe Agencia e adicionar os dois comandos no main().
- Mudei algo no plano antes de liberar? Não. O plano estava de acordo com o que a missão pedia, então autorizei a implementação.
- Resultado de `testar.sh missao1` e de `testar.sh parte1`: 2 de 2 testes passaram na Missão 1 e 6 de 6 testes passaram na Parte 1.
- Precisei refazer? O que mudou no pedido:Não precisei refazer. O primeiro pedido funcionou e os testes passaram.

## Missão 2: SALVAR e CARREGAR

- Primeira mensagem: pedi ao OpenCode para implementar os comandos SALVAR nome_do_arquivo e CARREGAR nome_do_arquivo, salvando e reconstruindo todos os dados dos astronautas e dos voos. Também pedi que primeiro apresentasse o plano sem editar os arquivos.
- O plano, resumido: a IA propôs adicionar <fstream>, criar construtores para reconstruir astronautas e voos com seus estados salvos, criar os métodos salvarDados() e carregarDados() na classe Agencia e adicionar os comandos no main(). Para o carregamento, seriam usados vetores temporários para manter os dados atuais caso houvesse erro.
- O formato do arquivo (cole cinco linhas do `dados_teste.txt`): astronautas 3 111 Ana Maria 30
- Resultado de `testar.sh missao2` e de `testar.sh parte1`: 3 de 3 testes passaram na Missão 2 e 6 de 6 testes passaram na Parte 1.
- Precisei refazer? O que mudou no pedido: Sim. Na primeira tentativa, o formato salvo não era compatível com a forma como o programa fazia a leitura. O marcador e a quantidade foram gravados juntos como astronautas:3, mas o carregamento esperava essas informações separadas. O teste de carregamento falhou. A IA corrigiu o formato para gravar astronautas e a quantidade em linhas separadas. Depois da correção, todos os testes passaram.

## Missão 3: RELATORIO

- Primeira mensagem: pedi ao OpenCode para implementar o comando RELATORIO, que mostra as informações dos voos e dos astronautas, além do astronauta mais experiente e da taxa de sucesso. Também pedi que primeiro apresentasse o plano sem editar os arquivos.
- O plano, resumido: a IA propôs criar o método contarVoosLancados() para calcular a experiência de cada astronauta a partir dos voos, criar o método relatorio() na classe Agencia para fazer as contagens e gerar o relatório, e adicionar o comando RELATORIO no main(). Não seria necessário alterar as classes Astronauta e Voo nem os comandos das missões anteriores.
- Resultado de `testar.sh missao3` e de `testar.sh parte1`: 5 de 5 testes passaram na Missão 3 e 6 de 6 testes passaram na Parte 1. A Missão 1 também passou com 2 de 2 testes e a Missão 2 com 3 de 3 testes.
- Precisei refazer? O que mudou no pedido: Não precisei refazer. A primeira implementação passou em todos os testes e não foi necessário mudar o pedido.

## Missão 4: livre

- O que escolhi e por quê: escolhi criar o comando DEMO, porque ele permite criar automaticamente um cenário de exemplo com astronautas e voos, facilitando a demonstração do programa sem precisar cadastrar todos os dados manualmente.
- O comando novo, a saída que eu esperava e o nome do meu arquivo de comandos (escritos antes de pedir): o comando novo será DEMO. Espero que ele crie o cenário de demonstração e mostre a mensagem OK: cenario de demonstracao criado. O arquivo de comandos é testes/missao4_demo.in, contendo os comandos DEMO, LISTAR_ASTRONAUTAS, LISTAR_VOOS e RELATORIO.
- Primeira mensagem: pedi ao OpenCode para implementar o comando DEMO, apresentando primeiro um plano sem editar os arquivos. O plano foi criar o método demo() na classe Agencia e adicionar o comando DEMO no main(). Também escolhi que o DEMO limparia os dados existentes antes de criar o cenário e que os objetos seriam adicionados diretamente aos vetores.
- O que veio, comparado com o que eu esperava: a implementação funcionou, mas houve uma diferença no resultado do astronauta mais experiente. Eu esperava que fosse o astronauta 444 Diego Lima, mas o resultado foi 111 Ana Maria. Isso aconteceu porque o voo em curso também conta como voo lançado. Assim, Ana e Diego ficaram com a mesma quantidade de voos lançados, e o primeiro astronauta cadastrado foi escolhido no empate.
- `testar.sh parte1` continuou passando? Sim. Os testes da Parte 1 continuaram passando, com 6 de 6 testes. A Missão 1 passou com 2 de 2, a Missão 2 com 3 de 3 e a Missão 3 com 5 de 5.
- Aceitei, ajustei ou descartei? Por quê: aceitei a implementação porque ela funcionou conforme as regras do programa e os testes continuaram passando. A diferença no astronauta mais experiente foi mantida porque está de acordo com a regra de contar voos em curso como voos lançados e, em caso de empate, escolher o primeiro astronauta cadastrado.

## Fechamento

- O que a IA fez que eu não conseguiria fazer sozinho nesse prazo:a IA me ajudou a desenvolver as Missões 1, 2, 3 e 4. Eu ainda estou aprendendo programação e não conseguiria escrever sozinho, dentro desse prazo, um código com tantos detalhes e funcionalidades. A IA também me ajudou a entender os erros encontrados nos testes e a corrigi-los.
- Onde ela errou ou fez algo que eu não pedi: na Missão 2, a primeira versão do formato de salvamento não funcionou corretamente com o carregamento, então foi necessário corrigir. Na Missão 4, o resultado do astronauta mais experiente foi diferente do que eu esperava inicialmente, mas depois verificamos que estava de acordo com as regras do programa.
- O que eu faria diferente da próxima vez: eu começaria a atividade com mais antecedência, para ter mais tempo para estudar o código, testar as funcionalidades e tirar minhas dúvidas com calma, sem precisar fazer tudo próximo do prazo de entrega.
