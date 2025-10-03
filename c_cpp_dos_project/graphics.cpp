#include <iostream>
#include <dos.h>

// Definir a interrupção 10h para mudar o modo de vídeo
void set_video_mode(int mode) {
    union REGS regs;
    regs.h.ah = 0x00;
    regs.h.al = mode;
    int86(0x10, &regs, &regs);
}

// Ponteiro para a memória de vídeo do Modo 13h
char far *vram = (char far *)0xA0000000L;

void putpixel(int x, int y, char color) {
    if (x >= 0 && x < 320 && y >= 0 && y < 200) {
        vram[y * 320 + x] = color;
    }
}

int main() {
    set_video_mode(0x13); // Modo 13h
    int x = 160, y = 100, dx = 1, dy = 1;
    char color = 15;
    while (!kbhit()) {
        putpixel(x, y, 0); // Apaga pixel antigo
        x += dx;
        y += dy;
        if (x >= 319 || x <= 0) { dx = -dx; color = (color + 1) % 256; }
        if (y >= 199 || y <= 0) { dy = -dy; color = (color + 1) % 256; }
        putpixel(x, y, color);
        delay(10);
    }
    getch();
    set_video_mode(0x03); // Volta ao modo texto
    return 0;
}
