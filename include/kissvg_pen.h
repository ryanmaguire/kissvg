/******************************************************************************
 *                                  LICENSE                                   *
 ******************************************************************************
 *  This file is part of KissVG.                                              *
 *                                                                            *
 *  KissVG is free software: you can redistribute it and/or modify            *
 *  it under the terms of the GNU General Public License as published by      *
 *  the Free Software Foundation, either version 3 of the License, or         *
 *  (at your option) any later version.                                       *
 *                                                                            *
 *  KissVG is distributed in the hope that it will be useful,                 *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 *  GNU General Public License for more details.                              *
 *                                                                            *
 *  You should have received a copy of the GNU General Public License         *
 *  along with KissVG.  If not, see <https://www.gnu.org/licenses/>.          *
 ******************************************************************************
 *                                 kissvg_pen                                 *
 ******************************************************************************
 *  Purpose:                                                                  *
 *      Provides tools for creating and using pens for vector graphics.       *
 ******************************************************************************
 *  Author:     Ryan Maguire                                                  *
 *  Date:       October 2, 2020                                               *
 ******************************************************************************
 *                              Revision History                              *
 ******************************************************************************
 *  2023/07/19: Ryan Maguire                                                  *
 *      Restructured everything, added more functions, changed pen typedef.   *
 ******************************************************************************/

/*  Include guard to prevent including this file twice.                       */
#ifndef KISSVG_PEN_H
#define KISSVG_PEN_H

#include <libtmpl/include/tmpl_bool.h>
#include <kissvg/include/kissvg_color.h>

/*  Primary struct used for drawing colors to an image.                       */
typedef struct kissvg_Pen_Def {
    const kissvg_Color *color;
    double alpha;
    double linewidth;
    tmpl_Bool has_transparency;
} kissvg_Pen;

/*  Default sizes for thin, medium, and thick pens, as well as axes.          */
#define KISSVG_AXES_PEN (1.0)
#define KISSVG_THIN_PEN (0.2)
#define KISSVG_THICK_PEN (0.8)
#define KISSVG_DEFAULT_PEN (0.4)

/*  Macros for accessing the data in the kissvg_Color struct.                 */
#define KISSVG_PEN_RED(pen) ((pen)->color->dat[0])
#define KISSVG_PEN_GREEN(pen) ((pen)->color->dat[1])
#define KISSVG_PEN_BLUE(pen) ((pen)->color->dat[2])
#define KISSVG_PEN_IS_TRANSPARENT(pen) ((pen)->has_transparency)
#define KISSVG_PEN_ALPHA(pen) ((pen)->alpha)
#define KISSVG_PEN_LINEWIDTH(pen) ((pen)->linewidth)

/******************************************************************************
 *  Function:                                                                 *
 *      kissvg_Pen_Copy                                                       *
 *  Purpose:                                                                  *
 *      Copy the values of one pen to another.                                *
 *  Arguments:                                                                *
 *      dest (kissvg_Pen *):                                                  *
 *          The pen that is to be written to.                                 *
 *      src (const kissvg_Pen *):                                             *
 *          The pen to be copied.                                             *
 *  Outputs:                                                                  *
 *      None (void).                                                          *
 ******************************************************************************/
extern void kissvg_Pen_Copy(kissvg_Pen *dest, const kissvg_Pen *src);

/******************************************************************************
 *  Function:                                                                 *
 *      kissvg_Pen_Create                                                     *
 *  Purpose:                                                                  *
 *      Creates a pen from a color and line width.                            *
 *  Arguments:                                                                *
 *      C (const kissvg_Color *):                                             *
 *          The color for the pen.                                            *
 *      linewidth (double):                                                   *
 *          The width of the pen, in Pts.                                     *
 *  Outputs:                                                                  *
 *      pen (kissvg_Pen).                                                     *
 *          A pen with color C and line width linewidth.                      *
 *  Notes:                                                                    *
 *      alpha is set to zero the has_transparency is set to false.            *
 ******************************************************************************/
extern kissvg_Pen kissvg_Pen_Create(const kissvg_Color *C, double linewidth);

/******************************************************************************
 *  Function:                                                                 *
 *      kissvg_Pen_Init                                                       *
 *  Purpose:                                                                  *
 *      Initialize a pen to a given color with default line width.            *
 *  Arguments:                                                                *
 *      pen (kissvg_Pen *):                                                   *
 *          The pen to be initialized.                                        *
 *      color (const kissvg_Color *):                                         *
 *          The color the pen is set to.                                      *
 *  Outputs:                                                                  *
 *      None (void).                                                          *
 *  Notes:                                                                    *
 *      The line width and transparency are set to default values.            *
 ******************************************************************************/
extern void kissvg_Pen_Init(kissvg_Pen *pen, const kissvg_Color *color);

/******************************************************************************
 *  Function:                                                                 *
 *      kissvg_Pen_Make_Empty                                                 *
 *  Purpose:                                                                  *
 *      Sets all parameters in a pen to their zero values.                    *
 *  Arguments:                                                                *
 *      pen (kissvg_Pen *):                                                   *
 *          The pen to be made empty.                                         *
 *  Outputs:                                                                  *
 *      None (void).                                                          *
 ******************************************************************************/
extern void kissvg_Pen_Make_Empty(kissvg_Pen *pen);

/******************************************************************************
 *  Function:                                                                 *
 *      kissvg_Pen_Set_Linewidth                                              *
 *  Purpose:                                                                  *
 *      Set the line width of a pen to a given value.                         *
 *  Arguments:                                                                *
 *      pen (kissvg_Pen *):                                                   *
 *          The pen whose thickness is to be set.                             *
 *      linewidth (double):                                                   *
 *          The desired line width.                                           *
 *  Outputs:                                                                  *
 *      None (void).                                                          *
 ******************************************************************************/
extern void kissvg_Pen_Set_Linewidth(kissvg_Pen *pen, double linewidth);

/******************************************************************************
 *  Function:                                                                 *
 *      kissvg_Pen_Set_Transparency                                           *
 *  Purpose:                                                                  *
 *      Set the alpha parameter of a pen to a given value.                    *
 *  Arguments:                                                                *
 *      pen (kissvg_Pen *):                                                   *
 *          The pen whose transparency is to be set.                          *
 *      linewidth (double):                                                   *
 *          The desired transparency.                                         *
 *  Outputs:                                                                  *
 *      None (void).                                                          *
 ******************************************************************************/
extern void kissvg_Pen_Set_Transparency(kissvg_Pen *pen, double alpha);

extern const kissvg_Pen kissvg_Blue_Pen;
extern const kissvg_Pen kissvg_Green_Pen;
extern const kissvg_Pen kissvg_Red_Pen;
extern const kissvg_Pen kissvg_Black_Pen;
extern const kissvg_Pen kissvg_White_Pen;
extern const kissvg_Pen kissvg_DarkGray_Pen;
extern const kissvg_Pen kissvg_Gray_Pen;
extern const kissvg_Pen kissvg_LightGray_Pen;
extern const kissvg_Pen kissvg_Aqua_Pen;
extern const kissvg_Pen kissvg_Purple_Pen;
extern const kissvg_Pen kissvg_Violet_Pen;
extern const kissvg_Pen kissvg_Pink_Pen;
extern const kissvg_Pen kissvg_Yellow_Pen;
extern const kissvg_Pen kissvg_Crimson_Pen;
extern const kissvg_Pen kissvg_DarkGreen_Pen;
extern const kissvg_Pen kissvg_Orange_Pen;
extern const kissvg_Pen kissvg_LightBlue_Pen;
extern const kissvg_Pen kissvg_Teal_Pen;
extern const kissvg_Pen kissvg_DarkBlue_Pen;
extern const kissvg_Pen kissvg_Lavender_Pen;
extern const kissvg_Pen kissvg_Magenta_Pen;
extern const kissvg_Pen kissvg_DeepPink_Pen;
extern const kissvg_Pen kissvg_Marine_Pen;
extern const kissvg_Pen kissvg_Lime_Pen;
extern const kissvg_Pen kissvg_Carrot_Pen;
extern const kissvg_Pen kissvg_Brown_Pen;
extern const kissvg_Pen kissvg_Azure_Pen;
extern const kissvg_Pen kissvg_Silver_Pen;
extern const kissvg_Pen kissvg_Sand_Pen;
extern const kissvg_Pen kissvg_Empty_Pen;

#endif
/*  End of include guard.                                                     */
