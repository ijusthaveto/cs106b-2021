#include "Plotter.h"
#include "strlib.h"
using namespace std;

#define PENDOWN "pendown"
#define PENUP "penup"
#define MOVEABS "moveabs"
#define MOVEREL "moverel"
#define PENCOLOR "pencolor"
#define PENWIDTH "penwidth"
#define DELIMTER " "
#define UP false
#define DOWN true

void penDown(bool & state);
void penUp(bool & state);
void moveAbs(bool & state, string line, double & x0, double & y0, PenStyle style);
void moveRel(bool & state, string line, double & x0, double & y0, PenStyle style);
void penColor(string line, PenStyle & style);
void penWidth(string line, PenStyle & style);
void getPrameters(string line, double & x, double & y);

void runPlotterScript(istream& input) {

    // State of the pen
    bool state = UP;

    // Current position
    double x0 = 0, y0 = 0;

    PenStyle style = {1, "black"};

    // Read all the lines of the script
    for (string line; getline(input, line); ) {

        line = toLowerCase(line);

        if (startsWith(line, PENDOWN)) {
            // PenDown
            penDown(state);
        } else if (startsWith(line, PENUP)) {
            // PenUp
            penUp(state);
        } else if (startsWith(line, MOVEABS)) {
            // MoveAbs
            moveAbs(state, line, x0, y0, style);
        } else if (startsWith(line, MOVEREL)) {
            // MoveRel
            moveRel(state, line, x0, y0, style);
        } else if (startsWith(line, PENCOLOR)) {
            // PenColor
            penColor(line, style);
        } else if (startsWith(line, PENWIDTH)) {
            // PenWidth
            penWidth(line, style);
        }
    }
}

void penDown(bool & state) {
    if (state == UP) {
        state = DOWN;
    }
}
void penUp(bool & state) {
    if (state == DOWN) {
        state = UP;
    }
}
void getPrameters(string line, double & x, double & y) {
    Vector<string> parameters = stringSplit(line, DELIMTER);
    x = stringToReal(parameters[1]), y = stringToReal(parameters[2]);
}
void moveAbs(bool & state, string line, double & x0, double & y0, PenStyle style) {
    double x1, y1;
    getPrameters(line, x1, y1);
    if (state == DOWN) {
        drawLine(x0, y0, x1, y1, style);
    }
    x0 = x1, y0 = y1;
}
void moveRel(bool & state, string line, double & x0, double & y0, PenStyle style) {
    double x1, y1;
    getPrameters(line, x1, y1);
    if (state == DOWN) {
        drawLine(x0, y0, x1 + x0, y1 + y0, style);
    }
    x0 += x1, y0 += y1;
}
void penColor(string line, PenStyle & style) {
    Vector<string> parameters = stringSplit(line, DELIMTER);
    style.color = parameters[1];
}
void penWidth(string line, PenStyle & style) {
    Vector<string> parameters = stringSplit(line, DELIMTER);
    style.width = stringToReal(parameters[1]);
}
