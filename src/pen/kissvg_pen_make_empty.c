#include <libtmpl/include/tmpl_bool.h>
#include <kissvg/include/kissvg_pen.h>
#include <stddef.h>

void kissvg_Pen_Make_Empty(kissvg_Pen *pen)
{
    if (!pen)
        return;

    pen->color = NULL;
    pen->alpha = 0.0;
    pen->linewidth = 0.0;
    pen->has_transparency = tmpl_False;
}
