#include <libtmpl/include/tmpl_bool.h>
#include <kissvg/include/kissvg_pen.h>

/*  Initializes a pen to a given color with default parameters.               */
void kissvg_Pen_Init(kissvg_Pen *pen, const kissvg_Color *color)
{
    /*  If the pointer to the pen is NULL there is nothing to do.             */
    if (!pen)
        return;

    /*  Otherwise set the parameters to defaults and the color to the input.  */
    pen->alpha = 0.0;
    pen->linewidth = 0.0;
    pen->has_transparency = tmpl_False;
    pen->color = color;
}
/*  End of kissvg_Pen_Init.                                                   */
