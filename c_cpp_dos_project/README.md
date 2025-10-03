# Projeto de Estudo C/C++ para Jogos DOS e Sistemas Legados
## Estrutura do Projeto
- `graphics.cpp`: Exemplo de manipulação gráfica em Modo 13h (DOS)
- `api_client.cpp`: Exemplo de consumo de API REST em C++ moderno
- `libmath.c` e `libmath.h`: Exemplo de biblioteca compartilhada em C
- `main.cpp`: Exemplo de uso da biblioteca compartilhada

## Como Compilar e Rodar no Windows

Pré-requisitos (linha de comando):
- MinGW-w64 instalado e no PATH (fornece `gcc`/`g++`). Alternativas: MSYS2 (pacote mingw64) ou Visual Studio Build Tools com `cl`.
- Para `api_client.cpp`: baixar cabeçalhos `httplib.h` e `nlohmann/json.hpp` em `third_party/include/`.

Com VS Code (Tasks):
- Abra a pasta no VS Code
- Pressione Ctrl+Shift+B e escolha:
  - "Build: main + libmath" para compilar `main.cpp` + `libmath.c` em `bin\program.exe`
  - "Build: api_client (needs headers)" para compilar o cliente REST
- Para rodar: execute a task "Run: program" ou, no terminal integrado, `bin\\program.exe`

Via script (alternativa rápida):
```
build_and_run.bat
```
O script compila `main.cpp` + `libmath.c` e executa `bin\program.exe`.

Compilação manual (alternativa):
```
g++ main.cpp libmath.c -std=c++17 -O2 -o bin\program.exe
bin\program.exe

g++ api_client.cpp -std=c++17 -O2 -I third_party\include -o bin\api_client.exe
bin\api_client.exe
```

Notas REST: `api_client.cpp` faz HTTPS. Se houver erro de SSL, teste com HTTP simples (troque a URL para `http://...`) ou instale OpenSSL e ajuste as flags de link.

## Gráficos DOS (graphics.cpp)
Este exemplo é para DOS (Modo 13h). Para rodar, use DOSBox + DJGPP:
1) Instale DOSBox
2) Baixe DJGPP (GCC para DOS) e extraia em `C:\djgpp`
3) Crie `C:\dos-dev`, copie `graphics.cpp` para lá
4) No DOSBox:
```
MOUNT C C:\dos-dev
C:
SET PATH=%PATH%;C:\djgpp\bin
g++ graphics.cpp -o graphics.exe
graphics.exe
```


