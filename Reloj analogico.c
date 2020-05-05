void draw_circ(char r)
{
    for (char fil = r; fil >= 0; fil--)
    {
        for (char col = 0; col < r+2; col++)
        {
            if(r==floor(0.5+sqrt(pow(col,2)+pow(fil,2))))
            {
                textbackground(1);
                gotoxy(CENTERX + col, CENTERY + fil);
                cprintf(" ");
                gotoxy(CENTERX - col, CENTERY + fil); // -x
                cprintf(" ");
                gotoxy(CENTERX + col, CENTERY - fil); // -y
                cprintf(" ");
                gotoxy(CENTERX - col, CENTERY - fil); // -x -y
                cprintf(" ");
            }
        }
    }
}

void draw_line(char xc, char yc, float ang, char r)
{
    char xf = floor(0.5 + xc + cos(ang+(M_PI/23))r);
    char yf = floor(0.5 + yc + sin(ang+(M_PI/23))r);
    char e2;
    char dx = abs(xf - xc);
    char sx = xc < xf ? 1 : -1;
    char dy = -abs(yf - yc);
    char sy = yc < yf ? 1 : -1;
    char err = dx + dy;
    textbackground(2);
    while (1) // Bresenham
    {
        gotoxy(xc,yc);
        cprintf(" ");
        if (xc==xf && yc==yf) break;
        e2 = 2*err;
        // TODO PREGUNTAR MULTIPLICAR *2 VS SUMAR

        if (e2 >= dy)
        {
            err += dy;
            xc += sx;
        }
        if (e2 <= dx)
        { 
            err += dx;
            yc += sy;
        }
    }
}