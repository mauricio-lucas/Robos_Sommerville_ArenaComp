# Contribuindo — guia para o time

Este guia é para quem **nunca usou git**. Siga na ordem — 15 minutos e você está contribuindo.

---

## 1. Instalar o que falta (uma vez só)

- **Git:** `sudo dnf install git` (Fedora) ou baixe em [git-scm.com](https://git-scm.com)
- **Arduino IDE 2.x:** [arduino.cc/en/software](https://www.arduino.cc/en/software)

Configure seu nome no git (uma vez só, para identificar seus commits):

```bash
git config --global user.name "Seu Nome"
git config --global user.email "seuemail@exemplo.com"
```

## 2. Clonar o repositório (uma vez só)

O clone baixa uma cópia completa do projeto para sua máquina.

```bash
cd ~/Projetos            # ou onde você guarda seus projetos
git clone <URL_DO_REPOSITORIO>.git
cd Robos_Sommerville_ArenaComp
```

> Peça a URL no grupo do time (página do repositório no GitHub/GitLab → botão verde **Code** → copie o link).

## 3. Antes de começar a mexer — sincronize sempre

Toda vez que for trabalhar, baixe as mudanças que os colegas fizeram:

```bash
git pull
```

## 4. Modificar o código

Abra a pasta do robô no Arduino IDE:

- Sumô: *File → Open →* `sumo/sumo.ino`
- Rampa: *File → Open →* `rampa/rampa.ino`

**Regras do projeto:**
1. Pinos e limiares só no `config.h` — nunca números mágicos no meio do código.
2. Mexeu em algo? Teste na bancada antes de enviar.
3. Ajustou uma calibração (ex.: `LINHA_PRETO_ACIMA_DE`)? Anote o valor no commit.

## 5. Enviar suas mudanças (commit + push)

Dentro da pasta do projeto:

```bash
# 1) veja o que você mudou
git status

# 2) prepare TODOS os arquivos alterados
git add .

# 3) salve uma "fotografia" das mudanças com uma mensagem clara
git commit -m "ajusta calibracao do IR da rampa (preto=480 no teste)"

# 4) envie para o repositório do time
git push
```

### Como escrever a mensagem do commit
- Curta e no presente/imperativo: o que o commit **faz**.
- Exemplos bons:
  - `corrige pino ECHO da borda no config (era D7, mudou p/ D8)`
  - `aumenta VEL_SUBIDA para 240 após teste na rampa real`
- Exemplos ruins: `arrumei coisas`, `teste`, `alterações`.

## 6. Se o `git push` reclamar que você está atrasado

Significa que um colega enviou algo enquanto você trabalhava:

```bash
git pull     # junta as mudanças dele com as suas
git push     # agora envia
```

Se o git abrir um editor de texto pedindo mensagem de merge, salve e feche (`:wq` no vim).

## 7. Fluxo resumido (cole no seu caderno)

```bash
git pull                  # 1. baixar novidades
# ... editar e testar ...
git add .                 # 2. preparar mudanças
git commit -m "mensagem"  # 3. fotografar
git push                  # 4. enviar
```

## 8. Emergências comuns

| Problema | Comando |
|---|---|
| "Que mudança eu fiz mesmo?" | `git diff` |
| Histórico do projeto | `git log --oneline` |
| Desfiz tudo que NÃO foi commitado | `git restore .` ⚠️ (perde as edições) |
| Errei a mensagem do último commit | `git commit --amend -m "nova mensagem"` |

Dúvidas? Chame o responsável do firmware do seu robô ou abra uma *issue* no repositório.
