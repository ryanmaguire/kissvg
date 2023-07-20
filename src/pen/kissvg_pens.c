#include <kissvg/include/kissvg_color.h>
#include <kissvg/include/kissvg_pen.h>
#include <stddef.h>

/*  The following are pre-defined colors for ease of use. This macro allows   *
 *  us to avoid repeatedly typing the same lines.                             */
#define KISSVG_SET_PEN(pen, color) \
const kissvg_Pen pen = {&color, 0.0, KISSVG_DEFAULT_PEN, tmpl_False}

/*  Create pens for all of the colors provided.                               */
KISSVG_SET_PEN(kissvg_Blue_Pen, kissvg_Blue);
KISSVG_SET_PEN(kissvg_Green_Pen, kissvg_Green);
KISSVG_SET_PEN(kissvg_Red_Pen, kissvg_Red);
KISSVG_SET_PEN(kissvg_Black_Pen, kissvg_Black);
KISSVG_SET_PEN(kissvg_White_Pen, kissvg_White);
KISSVG_SET_PEN(kissvg_DarkGray_Pen, kissvg_DarkGray);
KISSVG_SET_PEN(kissvg_Gray_Pen, kissvg_Gray);
KISSVG_SET_PEN(kissvg_LightGray_Pen, kissvg_LightGray);
KISSVG_SET_PEN(kissvg_Aqua_Pen, kissvg_Aqua);
KISSVG_SET_PEN(kissvg_Purple_Pen, kissvg_Purple);
KISSVG_SET_PEN(kissvg_Violet_Pen, kissvg_Violet);
KISSVG_SET_PEN(kissvg_Pink_Pen, kissvg_Pink);
KISSVG_SET_PEN(kissvg_Yellow_Pen, kissvg_Yellow);
KISSVG_SET_PEN(kissvg_Crimson_Pen, kissvg_Crimson);
KISSVG_SET_PEN(kissvg_DarkGreen_Pen, kissvg_DarkGreen);
KISSVG_SET_PEN(kissvg_Orange_Pen, kissvg_Orange);
KISSVG_SET_PEN(kissvg_LightBlue_Pen, kissvg_LightBlue);
KISSVG_SET_PEN(kissvg_Teal_Pen, kissvg_Teal);
KISSVG_SET_PEN(kissvg_DarkBlue_Pen, kissvg_DarkBlue);
KISSVG_SET_PEN(kissvg_Lavender_Pen, kissvg_Lavender);
KISSVG_SET_PEN(kissvg_Magenta_Pen, kissvg_Magenta);
KISSVG_SET_PEN(kissvg_DeepPink_Pen, kissvg_DeepPink);
KISSVG_SET_PEN(kissvg_Marine_Pen, kissvg_Marine);
KISSVG_SET_PEN(kissvg_Lime_Pen, kissvg_Lime);
KISSVG_SET_PEN(kissvg_Carrot_Pen, kissvg_Carrot);
KISSVG_SET_PEN(kissvg_Brown_Pen, kissvg_Brown);
KISSVG_SET_PEN(kissvg_Azure_Pen, kissvg_Azure);
KISSVG_SET_PEN(kissvg_Silver_Pen, kissvg_Silver);
KISSVG_SET_PEN(kissvg_Sand_Pen, kissvg_Sand);

/*  Undefine the macro in case someone wants to #include this file.           */
#undef KISSVG_SET_PEN

/*  The empty pen has zero values for all parameters. The color is NULL.      */
const kissvg_Pen kissvg_Empty_Pen = {NULL, 0.0, 0.0, tmpl_False};
