#ifndef KISSVG_LABEL_H
#define KISSVG_LABEL_H

#include <libtmpl/include/tmpl_vec2.h>
#include <kissvg/include/kissvg_pen.h>

/*  Struct for adding labels to figures.                                      */
typedef struct kissvg_Label_Def {
    char *label_content;
    unsigned int font_size;
    unsigned int baseline_skip;
    double margins[4];
    const tmpl_TwoVectorDouble *anchor;
    const tmpl_TwoVectorDouble *shift;
    const kissvg_Pen *pen;
} kissvg_Label;

#endif
