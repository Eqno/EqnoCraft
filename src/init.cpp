#include "base.h"
#include "init.h"
#include "loader.h"
#include "bedrock.h"
#include "ground.h"

GLint
    BEDROCKTEX,  // bedrock
    STONETEX,  // stone
    DIRTTEX,  /// dirt
    GRASSTOPTEX, GRASSSIDETEX, GRASSBOTTOMTEX;  // grass

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
    BEDROCKTEX = loadTexture("tex/texture/bedrock.bmp");
    STONETEX = loadTexture("tex/texture/stone.bmp");
    DIRTTEX = loadTexture("tex/texture/dirt.bmp");
    GRASSTOPTEX = loadTexture("tex/texture/grass/grass_block_top.bmp");
    GRASSSIDETEX = loadTexture("tex/texture/grass/grass_block_side.bmp");
    GRASSBOTTOMTEX = loadTexture("tex/texture/grass/grass_block_bottom.bmp");
}

void initBedrock()
{
    for (int i=-WORLDWIDTH; i<=WORLDWIDTH; i++)
        for (int j=-WORLDLENGTH; j<=WORLDLENGTH; j++)
            addBedrock(i, BEDROCKDEPTH, j);
}

void initGround()
{
    for (int k=BEDROCKDEPTH+1; k<=-5; k++)
        for (int i=-WORLDWIDTH; i<=WORLDWIDTH; i++)
            for (int j=-WORLDLENGTH; j<=WORLDLENGTH; j++)
                addStone(i, k, j);
    for (int k=-4; k<=-2; k++)
        for (int i=-WORLDWIDTH; i<=WORLDWIDTH; i++)
            for (int j=-WORLDLENGTH; j<=WORLDLENGTH; j++)
                addDirt(i, k, j);
    for (int i=-WORLDWIDTH; i<=WORLDWIDTH; i++)
        for (int j=-WORLDLENGTH; j<=WORLDLENGTH; j++)
            addGrass(i, -1, j);
}

void initActor() { addActor(); }