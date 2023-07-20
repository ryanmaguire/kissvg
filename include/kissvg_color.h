#ifndef KISSVG_COLOR_H
#define KISSVG_COLOR_H

typedef struct kissvg_Color_Def {
    double dat[3];
} kissvg_Color;

extern kissvg_Color kissvg_Color_Create(double red, double green, double blue);
extern kissvg_Color kissvg_Color_Add(const kissvg_Color *C0, const kissvg_Color *C1);
extern void kissvg_Color_AddTo(kissvg_Color *C0, const kissvg_Color *C1);
extern kissvg_Color kissvg_Color_Scale(double r, const kissvg_Color *C);
extern void kissvg_Color_ScaleBy(kissvg_Color *C, double r);

extern const kissvg_Color kissvg_Blue;
extern const kissvg_Color kissvg_Green;
extern const kissvg_Color kissvg_Red;
extern const kissvg_Color kissvg_Black;
extern const kissvg_Color kissvg_White;
extern const kissvg_Color kissvg_DarkGray;
extern const kissvg_Color kissvg_Gray;
extern const kissvg_Color kissvg_LightGray;
extern const kissvg_Color kissvg_Aqua;
extern const kissvg_Color kissvg_Purple;
extern const kissvg_Color kissvg_Violet;
extern const kissvg_Color kissvg_Pink;
extern const kissvg_Color kissvg_Yellow;
extern const kissvg_Color kissvg_Crimson;
extern const kissvg_Color kissvg_DarkGreen;
extern const kissvg_Color kissvg_Orange;
extern const kissvg_Color kissvg_LightBlue;
extern const kissvg_Color kissvg_Teal;
extern const kissvg_Color kissvg_DarkBlue;
extern const kissvg_Color kissvg_Lavender;
extern const kissvg_Color kissvg_Magenta;
extern const kissvg_Color kissvg_DeepPink;
extern const kissvg_Color kissvg_Marine;
extern const kissvg_Color kissvg_Lime;
extern const kissvg_Color kissvg_Carrot;
extern const kissvg_Color kissvg_Brown;
extern const kissvg_Color kissvg_Azure;
extern const kissvg_Color kissvg_Silver;
extern const kissvg_Color kissvg_Sand;

#endif
