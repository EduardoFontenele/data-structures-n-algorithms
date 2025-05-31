# GCC Compilation Guide

## 📋 Visão Geral

Este guia explica como compilar projetos C com múltiplas dependências usando GCC, desde compilação simples até projetos complexos com bibliotecas externas.

## 🔧 Flags Essenciais do GCC

| Flag | Propósito | Exemplo |
|------|-----------|---------|
| `-c` | Compila sem linkar (gera .o) | `gcc -c file.c -o file.o` |
| `-o` | Especifica nome do executável | `gcc file.c -o programa` |
| `-I` | Adiciona diretório de headers | `gcc -Iheaders file.c` |
| `-L` | Adiciona diretório de bibliotecas | `gcc -Llib file.c` |
| `-l` | Linka biblioteca específica | `gcc file.c -lmath` |
| `-Wall` | Habilita warnings básicos | `gcc -Wall file.c` |
| `-Wextra` | Warnings extras | `gcc -Wall -Wextra file.c` |
| `-std=c99` | Especifica padrão C | `gcc -std=c99 file.c` |
| `-g` | Informações de debug | `gcc -g file.c` |

## 🎯 Processo de Compilação

### 1. Arquivo Único
```bash
# Compilação direta
gcc programa.c -o programa

# Com flags de qualidade
gcc -Wall -Wextra -std=c99 -g programa.c -o programa
```

### 2. Múltiplos Arquivos na Mesma Pasta
```bash
# Compila tudo junto
gcc main.c utils.c math.c -o programa

# Com headers em subpasta
gcc main.c utils.c math.c -Iheaders -o programa
```

### 3. Compilação Separada (Recomendado)

#### Passo 1: Compilar para objetos (.o)
```bash
# Compila cada .c para .o
gcc -c main.c -Iheaders -o main.o
gcc -c utils.c -Iheaders -o utils.o
gcc -c math.c -Iheaders -o math.o
```

#### Passo 2: Linkar objetos
```bash
# Junta todos os .o em executável
gcc main.o utils.o math.o -o programa
```

## 🏗️ Projetos com Estrutura de Pastas

### Estrutura Típica
```
projeto/
├── src/           # Arquivos .c
├── headers/       # Arquivos .h
├── obj/           # Arquivos .o (gerados)
├── lib/           # Bibliotecas externas
└── bin/           # Executáveis finais
```

### Comandos por Pasta
```bash
# Compilar sources para objetos
gcc -c src/main.c -Iheaders -o obj/main.o
gcc -c src/utils.c -Iheaders -o obj/utils.o

# Linkar objetos
gcc obj/main.o obj/utils.o -o bin/programa
```

## 🔗 Dependências Externas

### Cenário: Projeto usa biblioteca externa

**Estrutura:**
```
workspace/
├── meu_projeto/
│   ├── src/main.c
│   └── headers/
└── biblioteca_externa/
    ├── src/lib.c
    ├── headers/lib.h
    └── obj/lib.o
```

### Ordem de Compilação

#### 1. Compilar dependência externa
```bash
# Dentro de biblioteca_externa/
gcc -c src/lib.c -Iheaders -o obj/lib.o
```

#### 2. Compilar projeto principal
```bash
# Dentro de meu_projeto/
gcc -c src/main.c -Iheaders -I../biblioteca_externa/headers -o obj/main.o
```

#### 3. Linkar tudo
```bash
# Dentro de meu_projeto/
gcc obj/main.o ../biblioteca_externa/obj/lib.o -o bin/programa
```

## ⚡ Comandos Completos Reais

### Exemplo 1: Projeto simples
```bash
# Uma linha só
gcc src/main.c src/utils.c -Iheaders -Wall -Wextra -std=c99 -g -o programa
```

### Exemplo 2: Com dependência externa
```bash
# Compilação completa de projeto complexo
gcc src/main.c \
    obj/local_lib.o \
    ../external_lib/obj/external.o \
    -Iheaders \
    -I../external_lib/headers \
    -Wall -Wextra -std=c99 -g \
    -o bin/programa
```

### Exemplo 3: Com bibliotecas do sistema
```bash
# Usando matemática e threading
gcc src/main.c obj/utils.o -Iheaders -lmath -lpthread -o programa
```

## 🔄 Workflow Recomendado

### Para Desenvolvimento
1. **Organizar estrutura** de pastas
2. **Compilar dependências** primeiro (bottom-up)
3. **Compilar projeto** principal
4. **Linkar** tudo junto

### Comandos em Sequência
```bash
# 1. Criar diretórios
mkdir -p obj bin

# 2. Compilar dependências
gcc -c ../dependency/src/dep.c -I../dependency/headers -o ../dependency/obj/dep.o

# 3. Compilar projeto
gcc -c src/main.c -Iheaders -I../dependency/headers -o obj/main.o

# 4. Linkar final
gcc obj/main.o ../dependency/obj/dep.o -o bin/programa
```

## 📝 Makefile Automático

Para projetos complexos, use Makefile:

```makefile
# Variáveis
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
SRCDIR = src
HEADERDIR = headers
OBJDIR = obj
BINDIR = bin

# Dependências externas
EXT_OBJDIR = ../external_lib/obj
EXT_HEADERDIR = ../external_lib/headers

# Target principal
programa: $(OBJDIR)/main.o $(EXT_OBJDIR)/external.o | $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $(BINDIR)/$@

# Compilar objetos locais
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(HEADERDIR) -I$(EXT_HEADERDIR) -c $< -o $@

# Criar diretórios
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: clean
```

## 🚨 Problemas Comuns

### "No such file or directory"
**Causa:** Caminho errado para headers ou sources
```bash
# ❌ Errado
gcc -Iheader src/main.c  # pasta chama "headers"

# ✅ Correto  
gcc -Iheaders src/main.c
```

### "Undefined reference to function"
**Causa:** Esqueceu de linkar objeto/biblioteca
```bash
# ❌ Só compilou main.c, mas usa funções de utils.c
gcc main.c -o programa

# ✅ Inclui utils.c ou utils.o
gcc main.c utils.c -o programa
```

### "Multiple definition"
**Causa:** Incluiu .c em vez de .h, ou linkOU o mesmo objeto duas vezes
```bash
# ❌ Errado - inclui implementação
#include "utils.c"

# ✅ Correto - inclui só declarações
#include "utils.h"
```

## 💡 Dicas Avançadas

### Debug de Linking
```bash
# Ver símbolos em objeto
nm arquivo.o

# Ver dependências dinâmicas
ldd programa

# Verbose linking
gcc -v arquivos... -o programa
```

### Otimização
```bash
# Debug
gcc -g -O0 arquivos... -o programa_debug

# Release
gcc -O2 -DNDEBUG arquivos... -o programa_release
```

### Cross-compilation
```bash
# Compile para 32-bit em sistema 64-bit
gcc -m32 arquivos... -o programa32
```

## 🎯 Checklist Rápido

- [ ] Estrutura de pastas organizada
- [ ] Headers (.h) separados de implementação (.c)
- [ ] Compilar dependências primeiro
- [ ] Usar `-I` para todos os diretórios de headers necessários
- [ ] Linkar todos os objetos (.o) necessários
- [ ] Testar com flags de warning (`-Wall -Wextra`)
- [ ] Makefile para projetos grandes

---

**Lembre-se:** GCC é poderoso mas verboso. Use Makefiles para automatizar comandos longos!