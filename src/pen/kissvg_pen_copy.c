#include <libtmpl/include/tmpl_bool.h>
#include <kissvg/include/kissvg_pen.h>
#include <stddef.h>

/*  Copies the parameters of the pen src to the pen dest.                     */
void kissvg_Pen_Copy(kissvg_Pen *dest, const kissvg_Pen *src)
{
    /*  If the destination pointer is NULL there is nothing to do.            */
    if (!dest)
        return;

    /*  If the source pointer is NULL set the destination to an empty pen.    */
    if (!src)
        kissvg_Pen_Make_Empty(dest);

    /*  Otherwise set the parameters in the dest pen to those in src.         */
    else
    {
        dest->color = src->color;
        dest->alpha = src->alpha;
        dest->linewidth = src->linewidth;
        dest->has_transparency = src->has_transparency;
    }
}
/*  End of kissvg_Pen_Copy.                                                   */
