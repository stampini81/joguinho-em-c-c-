# 🎮 Projeto C/C++ para Jogos DOS e Sistemas Legados# Projeto C/C++ para Jogos DOS e Sistemas Legados

## Estrutura do Projeto

## 📁 Estrutura do Projeto- `graphics.cpp`: Exemplo de manipulação gráfica em Modo 13h (DOS)

```- `api_client.cpp`: Exemplo de consumo de API REST em C++ moderno

c_cpp_dos_project/- `libmath.c` e `libmath.h`: Exemplo de biblioteca compartilhada em C

├── bin/                 # Executáveis compilados- `main.cpp`: Exemplo de uso da biblioteca compartilhada

├── third_party/         # Bibliotecas externas

│   └── include/## Como Compilar e Rodar no Windows

│       ├── httplib.h    # HTTP client library

│       └── nlohmann/    # JSON libraryPré-requisitos (linha de comando):

├── .vscode/- MinGW-w64 instalado e no PATH (fornece `gcc`/`g++`). Alternativas: MSYS2 (pacote mingw64) ou Visual Studio Build Tools com `cl`.

│   └── tasks.json       # Tasks do VS Code configuradas- Para `api_client.cpp`: baixar cabeçalhos `httplib.h` e `nlohmann/json.hpp` em `third_party/include/`.

├── main.cpp             # ✅ Programa principal funcionando

├── libmath.c            # ✅ Biblioteca matemáticaCom VS Code (Tasks):

├── libmath.h            # ✅ Headers da biblioteca- Abra a pasta no VS Code

├── graphics.cpp         # Gráficos DOS (requer DOSBox)- Pressione Ctrl+Shift+B e escolha:

├── api_client.cpp       # Cliente REST HTTP  - "Build: main + libmath" para compilar `main.cpp` + `libmath.c` em `bin\program.exe`

└── build_and_run.bat    # ✅ Script automatizado  - "Build: api_client (needs headers)" para compilar o cliente REST

```- Para rodar: execute a task "Run: program" ou, no terminal integrado, `bin\\program.exe`



## 🚀 Instalação Completa - Passo a PassoVia script (alternativa rápida):

```

### 1. **Instalar MSYS2 + MinGW-w64**build_and_run.bat

```

**Baixar e instalar MSYS2:**O script compila `main.cpp` + `libmath.c` e executa `bin\program.exe`.

```powershell

# Baixar instaladorCompilação manual (alternativa):

Invoke-WebRequest -Uri "https://github.com/msys2/msys2-installer/releases/latest/download/msys2-x86_64-latest.exe" -OutFile "msys2-installer.exe"```

g++ main.cpp libmath.c -std=c++17 -O2 -o bin\program.exe

# Executar instaladorbin\program.exe

Start-Process -FilePath ".\msys2-installer.exe" -Wait

```g++ api_client.cpp -std=c++17 -O2 -I third_party\include -o bin\api_client.exe

bin\api_client.exe

**Instalar compilador C/C++:**```

```bash

# No terminal MSYS2 ou via PowerShellNotas REST: `api_client.cpp` faz HTTPS. Se houver erro de SSL, teste com HTTP simples (troque a URL para `http://...`) ou instale OpenSSL e ajuste as flags de link.

C:\msys64\usr\bin\bash.exe -lc "pacman -Syu"

C:\msys64\usr\bin\bash.exe -lc "pacman -S --noconfirm mingw-w64-x86_64-toolchain"## Gráficos DOS (graphics.cpp)

```Este exemplo é para DOS (Modo 13h). Para rodar, use DOSBox + DJGPP:

1) Instale DOSBox

**Adicionar ao PATH (permanente):**2) Baixe DJGPP (GCC para DOS) e extraia em `C:\djgpp`

```powershell3) Crie `C:\dos-dev`, copie `graphics.cpp` para lá

[Environment]::SetEnvironmentVariable("PATH", [Environment]::GetEnvironmentVariable("PATH", "User") + ";C:\msys64\mingw64\bin", "User")4) No DOSBox:

``````

MOUNT C C:\dos-dev

### 2. **Baixar Dependências REST (Opcional)**C:

SET PATH=%PATH%;C:\djgpp\bin

```powershellg++ graphics.cpp -o graphics.exe

# Criar diretóriosgraphics.exe

mkdir -p third_party\include\nlohmann```



# Baixar bibliotecas

Invoke-WebRequest -Uri "https://raw.githubusercontent.com/yhirose/cpp-httplib/master/httplib.h" -OutFile "third_party\include\httplib.h"
Invoke-WebRequest -Uri "https://raw.githubusercontent.com/nlohmann/json/develop/single_include/nlohmann/json.hpp" -OutFile "third_party\include\nlohmann\json.hpp"
```

## ⚡ Como Usar

### **Método 1: Script Automatizado (Mais Fácil)**
```powershell
.\build_and_run.bat
```

### **Método 2: VS Code Tasks**
1. Abra o projeto no VS Code
2. Pressione `Ctrl+Shift+P` → "Tasks: Run Task"
3. Escolha:
   - **"Build: main + libmath"** → Compila o projeto principal
   - **"Run: program"** → Executa o programa

### **Método 3: Compilação Manual**
```powershell
# Criar pasta bin
mkdir bin

# Compilar projeto principal
g++ main.cpp libmath.c -std=c++17 -O2 -o bin\program.exe

# Executar
.\bin\program.exe

# Compilar cliente REST (se dependências instaladas)
g++ api_client.cpp -std=c++17 -O2 -I third_party\include -o bin\api_client.exe
```

## 🎯 Exemplos Funcionais

### **✅ main.cpp + libmath** 
**Status: 100% Funcional**
```cpp
// Usa biblioteca matemática personalizada
5 + 3 = 8
10 - 4 = 6
```

### **⚠️ api_client.cpp**
**Status: Dependências baixadas, ajustes necessários para Windows**
```cpp
// Cliente REST para APIs HTTP
// Requer ajustes para Windows 10+
```

### **🕹️ graphics.cpp** 
**Status: Somente para DOS (DOSBox)**
```cpp
// Gráficos VGA Mode 13h
// Requer DOSBox + DJGPP
```

## 🔧 Configuração DOS (graphics.cpp)

Para rodar o exemplo de gráficos DOS:

1. **Instalar DOSBox**
2. **Baixar DJGPP** e extrair em `C:\djgpp`
3. **Configurar no DOSBox:**
```
MOUNT C C:\dos-dev
C:
SET PATH=%PATH%;C:\djgpp\bin
g++ graphics.cpp -o graphics.exe
graphics.exe
```

## 🛠️ Ferramentas Instaladas

- ✅ **GCC/G++ 15.2.0** (via MSYS2)
- ✅ **Make, GDB, Binutils** (conjunto completo)
- ✅ **Tasks VS Code** configuradas
- ✅ **PATH do sistema** configurado
- ✅ **Script build automatizado**
- ✅ **Bibliotecas REST** baixadas

## 📝 Notas Técnicas

- **Compilador:** MinGW-w64 via MSYS2
- **Padrão C++:** C++17
- **Otimização:** -O2
- **Plataforma:** Windows 10/11
- **IDE:** VS Code com tasks configuradas
- **Build:** Automatizado via .bat e tasks.json

## 🎉 Status do Projeto

**✅ PROJETO 100% CONFIGURADO E FUNCIONAL!**

- Compilador instalado e funcionando
- Exemplo principal executando perfeitamente
- Ambiente de desenvolvimento completo
- Pronto para desenvolvimento C/C++