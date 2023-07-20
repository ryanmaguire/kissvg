/*  Booleans found here.                                                      */
#include <libtmpl/include/tmpl_bool.h>

/*  Function prototype and pen typedef provided here.                         */
#include <kissvg/include/kissvg_pen.h>

/*  Creates a pen from a given line width and color.                          */
kissvg_Pen kissvg_Pen_Create(const kissvg_Color *C, double linewidth)
{
    kissvg_Pen pen;
    pen.color = C;
    pen.linewidth = linewidth;
    pen.alpha = 0.0;
    pen.has_transparency = tmpl_False;
    return pen;
}
/*  End of kissvg_Pen_Create.                                                 */
