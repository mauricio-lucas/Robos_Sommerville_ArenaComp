<img src="./assets/robos_sommerville.png" alt="ilustracao de dois robôs" min-width="400px" max-width="800px" width="800px" align="center">

# Robos_Sommerville_ArenaComp

Firmware dos dois robôs da gincana universitária:

- **`sumo/`** — robô de sumô: encontra o oponente (VL53L0X via TCA9548A), empurra para fora e não cai da borda (HC-SR04 para baixo).
- **`rampa/`** — robô sobe-rampa: segue linha com sensor IR TCRT5000.

Documentação do projeto (orçamento, cronograma, riscos): [`plano-execucao.md`](plano-execucao.md).
Primeira vez contribuindo? → [`CONTRIBUTING.md`](CONTRIBUTING.md) (tutorial de clone/commit para iniciantes).

## ⚡ Como Executar

**Pré-requisitos:** Arduino IDE 2.x e cabo USB (tipo B) do Arduino Uno.

1. **Instalar bibliotecas** (só para o sumô): *Sketch → Include Library → Manage Libraries* → buscar e instalar:
   - `Adafruit VL53L0X`
   - `Adafruit TCA9548A`
2. **Abrir o sketch:** *File → Open* → `sumo/sumo.ino` ou `rampa/rampa.ino`
   (a IDE carrega a pasta inteira — os módulos `.c/.h` na mesma pasta são compilados junto).
3. **Selecionar a placa e a porta:** *Tools → Board → Arduino Uno*; *Tools → Port* → a porta em que o Uno apareceu (algo como `/dev/ttyUSB0` ou `/dev/ttyACM0`).
4. **Compilar:** ✅ *Verify* (Ctrl+R) — confere se o código compila.
5. **Gravar:** → *Upload* (Ctrl+U) com o Uno conectado.
6. **Ver o robô "pensando":** *Tools → Serial Monitor* em **115200 baud** — o robô imprime status, leituras de sensor e mensagens de start.

> O robô só entra em ação depois do **botão de start** (pino D12) — ele não anda sozinho ao ligar.

## Estrutura

```
Robos_Sommerville_ArenaComp/
├── CONTRIBUTING.md          # tutorial de git para iniciantes (clonar/modificar/commit)
├── plano-execucao.md      # plano completo: orçamento, cronograma, riscos
├── docs/                  # esquemas do Tinkercad, tabela de pinos, montagem
├── cad/                   # STLs da carcaça escolhidos
├── sumo/                  # firmware do robô sumô (sketch do Arduino IDE)
│   ├── sumo.ino           # programa principal (setup + loop + lógica)
│   ├── config.h           # PINOS e constantes — ÚNICO lugar que muda ao religar fios
│   ├── motor.h / motor.c  # módulo: controle dos motores via ponte H
│   └── sensores.h / sensores.cpp  # módulo: VL53L0X (mux) + HC-SR04 (borda)
└── rampa/                 # firmware do robô sobe-rampa
    ├── rampa.ino
    ├── config.h
    └── motor.h / motor.c
```

## Regra de ouro do projeto

**Nenhum número de pino no meio do código.** Todos os pinos e constantes de calibração ficam em `config.h`, no topo, comentados. Mudou a ligação na protoboard → muda só o `config.h`.

> O módulo `motor.c/.h` existe duplicado em `sumo/` e `rampa/` **de propósito**: cada sketch é autossuficiente, então mexer no de um não quebra o outro. Se corrigir um bug no motor, corrija nas duas cópias (ou avise o responsável do outro robô).

## Onde está cada coisa

| Preciso de... | Vá em... |
| --- | --- |
| Orçamento, lista de compras, cronograma | `plano-execucao.md` |
| Que pino liga em quê | `docs/tabela-pinos.md` e `config.h` de cada robô |
| Esquema elétrico | `docs/esquema-sumo.md` / `docs/esquema-rampa.md` (prints do Tinkercad) |
| Passo a passo de montagem | `docs/montagem.md` |
| STL da carcaça | `cad/` |
| Como clonar, modificar e enviar código | [`CONTRIBUTING.md`](CONTRIBUTING.md) |

---

## 🤝 Contribuindo

Primeira vez com git? Não sabe como enviar suas mudanças?
Siga o tutorial passo a passo em **[CONTRIBUTING.md](CONTRIBUTING.md)** — clonar, modificar, commit e push em 15 minutos.
