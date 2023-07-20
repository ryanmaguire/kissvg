#include <kissvg/include/kissvg_pen.h>

/*  Function for setting the transparency parameter of a pen to a given value.*/
void kissvg_Pen_Set_Transparency(kissvg_Pen *pen, double alpha)
{
    /*  If the pointer is NULL there is nothing to be done.                   */
    if (!pen)
        return;

    /*  If we have a valid pen, set the alpha parameter to the desired value. */
    pen->alpha = alpha;
}
/*  End of kissvg_Pen_Set_Transparency.                                       */
