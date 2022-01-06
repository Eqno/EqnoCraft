#include "base.h"
#include "init.h"
#include "loader.h"
#include "bedrock.h"
#include "ground.h"

GLint BEDROCKTEX = 0;

void createWindow(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WINWIDTH, WINHEIGHT); 
    glutInitWindowPosition(WINPOSX, WINPOSY);
    glutCreateWindow(WINTITLE.c_str());
}

void loadTexture()
{
    BEDROCKTEX = loadTexture("tex/bedrock.bmp");
}

void initBedrock()
{
    for (int i=-WORLDWIDTH; i<=WORLDWIDTH; i++)
        for (int j=-WORLDLENGTH; j<=WORLDLENGTH; j++)
            addBedrock(i, BEDROCKDEPTH, j);
}

void initGround()
{
    for (int k=BEDROCKDEPTH+1; k<=-2; k++)
        for (int i=-WORLDWIDTH; i<=WORLDWIDTH; i++)
            for (int j=-WORLDLENGTH; j<=WORLDLENGTH; j++)
                addStone(i, k, j);
}