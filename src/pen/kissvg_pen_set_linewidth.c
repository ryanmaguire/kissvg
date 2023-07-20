#include <kissvg/include/kissvg_pen.h>

/*  Function for setting the line width parameter of a pen to a given value.  */
void kissvg_Pen_Set_Linewidth(kissvg_Pen *pen, double linewidth)
{
    /*  If the pointer is NULL there is nothing to be done.                   */
    if (!pen)
        return;

    /*  If we have a valid pen, set the line width parameter to the input.    */
    pen->linewidth = linewidth;
}
/*  End of kissvg_Pen_Set_Linewidth.                                          */
