

## 🎮 Projeto C/C++ para Jogos DOS e Sistemas Legados

<br>

### 📁 Estrutura do Projeto

```
c_cpp_dos_project/
├── bin/                       # Executáveis compilados
├── third_party/               # Bibliotecas externas
│   └── include/
│       ├── httplib.h          # HTTP client library
│       └── nlohmann/          # JSON library
├── .vscode/
│   └── tasks.json             # Tasks do VS Code configuradas
├── main.cpp                   # ✅ Programa principal
├── libmath.c                  # ✅ Biblioteca matemática
├── libmath.h                  # ✅ Headers da biblioteca
├── graphics.cpp               # Gráficos DOS (requer DOSBox)
├── api_client.cpp             # Cliente REST HTTP
└── build_and_run.bat          # ✅ Script automatizado
```

-----

### 🚀 Instalação Completa - Passo a Passo

#### 1\. **Instalar MSYS2 + MinGW-w64**

Baixe e instale o MSYS2. Depois, use o terminal para instalar o compilador C/C++:

```bash
# No terminal MSYS2 ou via PowerShell
C:\msys64\usr\bin\bash.exe -lc "pacman -Syu"
C:\msys64\usr\bin\bash.exe -lc "pacman -S --noconfirm mingw-w64-x86_64-toolchain"
```

Adicione o compilador ao PATH do sistema:

```powershell
[Environment]::SetEnvironmentVariable("PATH", [Environment]::GetEnvironmentVariable("PATH", "User") + ";C:\msys64\mingw64\bin", "User")
```

#### 2\. **Baixar Dependências REST (Opcional)**

Execute os comandos abaixo para baixar as bibliotecas necessárias para `api_client.cpp`:

```powershell
# Criar diretórios
mkdir -p third_party\include\nlohmann

# Baixar bibliotecas
Invoke-WebRequest -Uri "https://raw.githubusercontent.com/yhirose/cpp-httplib/master/httplib.h" -OutFile "third_party\include\httplib.h"
Invoke-WebRequest -Uri "https://raw.githubusercontent.com/nlohmann/json/develop/single_include/nlohmann/json.hpp" -OutFile "third_party\include\nlohmann\json.hpp"
```

-----

### ⚡ Como Usar

#### **Método 1: Script Automatizado (Mais Fácil)**

Basta executar o script no terminal:

```powershell
.\build_and_run.bat
```

Este script compila `main.cpp` e `libmath.c`, depois executa o programa.

#### **Método 2: VS Code Tasks**

Abra o projeto no VS Code e pressione `Ctrl+Shift+B` para abrir a lista de tasks:

  * **"Build: main + libmath"**: compila o projeto principal.
  * **"Build: api\_client (needs headers)"**: compila o cliente REST.
  * **"Run: program"**: executa o programa compilado.

#### **Método 3: Compilação Manual**

```powershell
# Compilar projeto principal
g++ main.cpp libmath.c -std=c++17 -O2 -o bin\program.exe

# Executar
.\bin\program.exe

# Compilar cliente REST (se dependências instaladas)
g++ api_client.cpp -std=c++17 -O2 -I third_party\include -o bin\api_client.exe
```

-----

### 🎯 Exemplos Funcionais

  * `**main.cpp` + `libmath**`
    Status: **100% Funcional**
  * `**api_client.cpp**`
    Status: **Dependências baixadas, ajustes necessários**
  * `**graphics.cpp**`
    Status: **Somente para DOS (DOSBox)**

-----

### 🔧 Configuração DOS (`graphics.cpp`)

Para rodar o exemplo de gráficos para DOS (Modo 13h):

1.  Instale o **DOSBox**.
2.  Baixe o **DJGPP** (GCC para DOS) e extraia para `C:\djgpp`.
3.  No DOSBox, configure o ambiente:

<!-- end list -->

```
MOUNT C C:\dos-dev
C:
SET PATH=%PATH%;C:\djgpp\bin
g++ graphics.cpp -o graphics.exe
graphics.exe
```

-----

### 🎉 Status do Projeto

**✅ PROJETO 100% CONFIGURADO E FUNCIONAL\!**

  * **Compilador:** GCC/G++ (via MSYS2)
  * **Padrão C++:** C++17
  * **Plataforma:** Windows 10/11
  * **Ferramentas:** VS Code, `tasks.json`, script automatizado
  * **Status:** Ambiente de desenvolvimento completo, pronto para codar.
