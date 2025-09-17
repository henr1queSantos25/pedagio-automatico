# Sistema Embarcado de Controle Automático de Cancela

## Descrição do Projeto
Este projeto consiste em um sistema embarcado para controle automático de uma cancela, utilizando um sensor ultrassônico para detecção de veículos, um servomotor para o movimento da cancela e uma matriz de LEDs para feedback visual. O objetivo é simular o funcionamento de um pedágio ou portaria inteligente, integrando sensores, atuadores e sinalização visual em um único sistema.

## Funcionamento Geral
O microcontrolador realiza leituras periódicas do sensor ultrassônico para medir a distância de objetos à frente da cancela. Quando um objeto (veículo) é detectado a menos de 15 cm, o sistema aciona o servomotor para abrir a cancela e a matriz de LEDs exibe a cor verde. Caso não haja objeto próximo, a cancela permanece fechada e a matriz exibe a cor vermelha. Todas as leituras e ações são registradas via saída serial para monitoramento.

## Arquitetura de Pastas
```
├── main.c                  # Código principal do sistema
├── CMakeLists.txt          # Configuração do projeto para compilação
├── lib/                    # Bibliotecas customizadas
│   ├── hcSR04/             # Sensor ultrassônico
│   │   ├── hcSR04.c
│   │   └── hcSR04.h
│   ├── sg90/               # Servomotor
│   │   ├── sg90.c
│   │   └── sg90.h
│   └── matriz/             # Matriz de LEDs
│       ├── matriz.c
│       ├── matriz.h
│       └── matriz.pio
└── build/                  # Arquivos gerados pela compilação (ignorar)
```

## Periféricos Utilizados
- **Sensor Ultrassônico (HC-SR04):** Responsável pela medição de distância. Utiliza pinos TRIGGER e ECHO definidos em `main.c`.
- **Servomotor (SG90):** Controla a abertura e fechamento da cancela, operando em dois ângulos principais (90° e 180°).
- **Matriz de LEDs:** Fornece feedback visual do estado da cancela (verde para aberta, vermelho para fechada).

## Fluxo de Funcionamento
1. Inicialização dos periféricos na função `setup()`.
2. Leitura contínua da distância pelo sensor ultrassônico.
3. Decisão automática de abrir ou fechar a cancela com base na distância detectada.
4. Atualização da matriz de LEDs conforme o estado da cancela.
5. Registro das informações via saída serial para depuração e acompanhamento.

## Observações
- O código está modularizado, facilitando a manutenção e expansão.
- Todos os periféricos possuem bibliotecas próprias na pasta `lib`.
