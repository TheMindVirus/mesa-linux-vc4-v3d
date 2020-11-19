/* DO NOT EDIT - This file generated automatically by gl_marshal.py script */

/*
 * Copyright (C) 2012 Intel Corporation
 * All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sub license,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.  IN NO EVENT SHALL
 * INTEL CORPORATION,
 * AND/OR THEIR SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#include "api_exec.h"
#include "glthread_marshal.h"
#include "bufferobj.h"
#include "dispatch.h"

#define COMPAT (ctx->API != API_OPENGL_CORE)

UNUSED static inline int safe_mul(int a, int b)
{
    if (a < 0 || b < 0) return -1;
    if (a == 0 || b == 0) return 0;
    if (a > INT_MAX / b) return -1;
    return a * b;
}

/* NewList: marshalled asynchronously */
struct marshal_cmd_NewList
{
   struct marshal_cmd_base cmd_base;
   GLuint list;
   GLenum mode;
};
void
_mesa_unmarshal_NewList(struct gl_context *ctx, const struct marshal_cmd_NewList *cmd)
{
   const GLuint list = cmd->list;
   const GLenum mode = cmd->mode;
   CALL_NewList(ctx->CurrentServerDispatch, (list, mode));
}
void GLAPIENTRY
_mesa_marshal_NewList(GLuint list, GLenum mode)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_NewList);
   struct marshal_cmd_NewList *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_NewList, cmd_size);
   cmd->list = list;
   cmd->mode = mode;
   if (COMPAT) ctx->GLThread.inside_dlist = true;
}


/* EndList: marshalled asynchronously */
struct marshal_cmd_EndList
{
   struct marshal_cmd_base cmd_base;
};
void
_mesa_unmarshal_EndList(struct gl_context *ctx, const struct marshal_cmd_EndList *cmd)
{
   CALL_EndList(ctx->CurrentServerDispatch, ());
}
void GLAPIENTRY
_mesa_marshal_EndList(void)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_EndList);
   struct marshal_cmd_EndList *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_EndList, cmd_size);
   (void) cmd;
   if (COMPAT) ctx->GLThread.inside_dlist = false;
}


/* CallList: marshalled asynchronously */
struct marshal_cmd_CallList
{
   struct marshal_cmd_base cmd_base;
   GLuint list;
};
void
_mesa_unmarshal_CallList(struct gl_context *ctx, const struct marshal_cmd_CallList *cmd)
{
   const GLuint list = cmd->list;
   CALL_CallList(ctx->CurrentServerDispatch, (list));
}
void GLAPIENTRY
_mesa_marshal_CallList(GLuint list)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_CallList);
   struct marshal_cmd_CallList *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_CallList, cmd_size);
   cmd->list = list;
}


/* CallLists: marshalled asynchronously */
struct marshal_cmd_CallLists
{
   struct marshal_cmd_base cmd_base;
   GLsizei n;
   GLenum type;
   /* Next (n * _mesa_calllists_enum_to_count(type)) bytes are GLvoid lists[n] */
};
void
_mesa_unmarshal_CallLists(struct gl_context *ctx, const struct marshal_cmd_CallLists *cmd)
{
   const GLsizei n = cmd->n;
   const GLenum type = cmd->type;
   GLvoid * lists;
   const char *variable_data = (const char *) (cmd + 1);
   lists = (GLvoid *) variable_data;
   CALL_CallLists(ctx->CurrentServerDispatch, (n, type, lists));
}
void GLAPIENTRY
_mesa_marshal_CallLists(GLsizei n, GLenum type, const GLvoid * lists)
{
   GET_CURRENT_CONTEXT(ctx);
   int lists_size = (n * _mesa_calllists_enum_to_count(type));
   int cmd_size = sizeof(struct marshal_cmd_CallLists) + lists_size;
   struct marshal_cmd_CallLists *cmd;
   if (unlikely(lists_size < 0 || (lists_size > 0 && !lists) || (unsigned)cmd_size > MARSHAL_MAX_CMD_SIZE)) {
      _mesa_glthread_finish_before(ctx, "CallLists");
      CALL_CallLists(ctx->CurrentServerDispatch, (n, type, lists));
      return;
   }
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_CallLists, cmd_size);
   cmd->n = n;
   cmd->type = type;
   char *variable_data = (char *) (cmd + 1);
   memcpy(variable_data, lists, lists_size);
}


/* DeleteLists: marshalled asynchronously */
struct marshal_cmd_DeleteLists
{
   struct marshal_cmd_base cmd_base;
   GLuint list;
   GLsizei range;
};
void
_mesa_unmarshal_DeleteLists(struct gl_context *ctx, const struct marshal_cmd_DeleteLists *cmd)
{
   const GLuint list = cmd->list;
   const GLsizei range = cmd->range;
   CALL_DeleteLists(ctx->CurrentServerDispatch, (list, range));
}
void GLAPIENTRY
_mesa_marshal_DeleteLists(GLuint list, GLsizei range)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_DeleteLists);
   struct marshal_cmd_DeleteLists *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_DeleteLists, cmd_size);
   cmd->list = list;
   cmd->range = range;
}


/* GenLists: marshalled synchronously */
GLuint GLAPIENTRY
_mesa_marshal_GenLists(GLsizei range)
{
   GET_CURRENT_CONTEXT(ctx);
   _mesa_glthread_finish_before(ctx, "GenLists");
   return CALL_GenLists(ctx->CurrentServerDispatch, (range));
}


/* ListBase: marshalled asynchronously */
struct marshal_cmd_ListBase
{
   struct marshal_cmd_base cmd_base;
   GLuint base;
};
void
_mesa_unmarshal_ListBase(struct gl_context *ctx, const struct marshal_cmd_ListBase *cmd)
{
   const GLuint base = cmd->base;
   CALL_ListBase(ctx->CurrentServerDispatch, (base));
}
void GLAPIENTRY
_mesa_marshal_ListBase(GLuint base)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_ListBase);
   struct marshal_cmd_ListBase *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_ListBase, cmd_size);
   cmd->base = base;
}


/* Begin: marshalled asynchronously */
struct marshal_cmd_Begin
{
   struct marshal_cmd_base cmd_base;
   GLenum mode;
};
void
_mesa_unmarshal_Begin(struct gl_context *ctx, const struct marshal_cmd_Begin *cmd)
{
   const GLenum mode = cmd->mode;
   CALL_Begin(ctx->CurrentServerDispatch, (mode));
}
void GLAPIENTRY
_mesa_marshal_Begin(GLenum mode)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Begin);
   struct marshal_cmd_Begin *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Begin, cmd_size);
   cmd->mode = mode;
}


/* Bitmap: marshalled synchronously */
void GLAPIENTRY
_mesa_marshal_Bitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte * bitmap)
{
   GET_CURRENT_CONTEXT(ctx);
   _mesa_glthread_finish_before(ctx, "Bitmap");
   CALL_Bitmap(ctx->CurrentServerDispatch, (width, height, xorig, yorig, xmove, ymove, bitmap));
}


/* Color3b: marshalled asynchronously */
struct marshal_cmd_Color3b
{
   struct marshal_cmd_base cmd_base;
   GLbyte red;
   GLbyte green;
   GLbyte blue;
};
void
_mesa_unmarshal_Color3b(struct gl_context *ctx, const struct marshal_cmd_Color3b *cmd)
{
   const GLbyte red = cmd->red;
   const GLbyte green = cmd->green;
   const GLbyte blue = cmd->blue;
   CALL_Color3b(ctx->CurrentServerDispatch, (red, green, blue));
}
void GLAPIENTRY
_mesa_marshal_Color3b(GLbyte red, GLbyte green, GLbyte blue)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Color3b);
   struct marshal_cmd_Color3b *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Color3b, cmd_size);
   cmd->red = red;
   cmd->green = green;
   cmd->blue = blue;
}


/* Color3bv: marshalled asynchronously */
struct marshal_cmd_Color3bv
{
   struct marshal_cmd_base cmd_base;
   GLbyte v[3];
};
void
_mesa_unmarshal_Color3bv(struct gl_context *ctx, const struct marshal_cmd_Color3bv *cmd)
{
   const GLbyte * v = cmd->v;
   CALL_Color3bv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Color3bv(const GLbyte * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Color3bv);
   struct marshal_cmd_Color3bv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Color3bv, cmd_size);
   memcpy(cmd->v, v, 3 * sizeof(GLbyte));
}


/* Color3d: marshalled asynchronously */
struct marshal_cmd_Color3d
{
   struct marshal_cmd_base cmd_base;
   GLdouble red;
   GLdouble green;
   GLdouble blue;
};
void
_mesa_unmarshal_Color3d(struct gl_context *ctx, const struct marshal_cmd_Color3d *cmd)
{
   const GLdouble red = cmd->red;
   const GLdouble green = cmd->green;
   const GLdouble blue = cmd->blue;
   CALL_Color3d(ctx->CurrentServerDispatch, (red, green, blue));
}
void GLAPIENTRY
_mesa_marshal_Color3d(GLdouble red, GLdouble green, GLdouble blue)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Color3d);
   struct marshal_cmd_Color3d *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Color3d, cmd_size);
   cmd->red = red;
   cmd->green = green;
   cmd->blue = blue;
}


/* Color3dv: marshalled asynchronously */
struct marshal_cmd_Color3dv
{
   struct marshal_cmd_base cmd_base;
   GLdouble v[3];
};
void
_mesa_unmarshal_Color3dv(struct gl_context *ctx, const struct marshal_cmd_Color3dv *cmd)
{
   const GLdouble * v = cmd->v;
   CALL_Color3dv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Color3dv(const GLdouble * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Color3dv);
   struct marshal_cmd_Color3dv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Color3dv, cmd_size);
   memcpy(cmd->v, v, 3 * sizeof(GLdouble));
}


/* Color3f: marshalled asynchronously */
struct marshal_cmd_Color3f
{
   struct marshal_cmd_base cmd_base;
   GLfloat red;
   GLfloat green;
   GLfloat blue;
};
void
_mesa_unmarshal_Color3f(struct gl_context *ctx, const struct marshal_cmd_Color3f *cmd)
{
   const GLfloat red = cmd->red;
   const GLfloat green = cmd->green;
   const GLfloat blue = cmd->blue;
   CALL_Color3f(ctx->CurrentServerDispatch, (red, green, blue));
}
void GLAPIENTRY
_mesa_marshal_Color3f(GLfloat red, GLfloat green, GLfloat blue)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Color3f);
   struct marshal_cmd_Color3f *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Color3f, cmd_size);
   cmd->red = red;
   cmd->green = green;
   cmd->blue = blue;
}


/* Color3fv: marshalled asynchronously */
struct marshal_cmd_Color3fv
{
   struct marshal_cmd_base cmd_base;
   GLfloat v[3];
};
void
_mesa_unmarshal_Color3fv(struct gl_context *ctx, const struct marshal_cmd_Color3fv *cmd)
{
   const GLfloat * v = cmd->v;
   CALL_Color3fv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Color3fv(const GLfloat * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Color3fv);
   struct marshal_cmd_Color3fv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Color3fv, cmd_size);
   memcpy(cmd->v, v, 3 * sizeof(GLfloat));
}


/* Color3i: marshalled asynchronously */
struct marshal_cmd_Color3i
{
   struct marshal_cmd_base cmd_base;
   GLint red;
   GLint green;
   GLint blue;
};
void
_mesa_unmarshal_Color3i(struct gl_context *ctx, const struct marshal_cmd_Color3i *cmd)
{
   const GLint red = cmd->red;
   const GLint green = cmd->green;
   const GLint blue = cmd->blue;
   CALL_Color3i(ctx->CurrentServerDispatch, (red, green, blue));
}
void GLAPIENTRY
_mesa_marshal_Color3i(GLint red, GLint green, GLint blue)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Color3i);
   struct marshal_cmd_Color3i *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Color3i, cmd_size);
   cmd->red = red;
   cmd->green = green;
   cmd->blue = blue;
}


/* Color3iv: marshalled asynchronously */
struct marshal_cmd_Color3iv
{
   struct marshal_cmd_base cmd_base;
   GLint v[3];
};
void
_mesa_unmarshal_Color3iv(struct gl_context *ctx, const struct marshal_cmd_Color3iv *cmd)
{
   const GLint * v = cmd->v;
   CALL_Color3iv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Color3iv(const GLint * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Color3iv);
   struct marshal_cmd_Color3iv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Color3iv, cmd_size);
   memcpy(cmd->v, v, 3 * sizeof(GLint));
}


/* Color3s: marshalled asynchronously */
struct marshal_cmd_Color3s
{
   struct marshal_cmd_base cmd_base;
   GLshort red;
   GLshort green;
   GLshort blue;
};
void
_mesa_unmarshal_Color3s(struct gl_context *ctx, const struct marshal_cmd_Color3s *cmd)
{
   const GLshort red = cmd->red;
   const GLshort green = cmd->green;
   const GLshort blue = cmd->blue;
   CALL_Color3s(ctx->CurrentServerDispatch, (red, green, blue));
}
void GLAPIENTRY
_mesa_marshal_Color3s(GLshort red, GLshort green, GLshort blue)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Color3s);
   struct marshal_cmd_Color3s *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Color3s, cmd_size);
   cmd->red = red;
   cmd->green = green;
   cmd->blue = blue;
}


/* Color3sv: marshalled asynchronously */
struct marshal_cmd_Color3sv
{
   struct marshal_cmd_base cmd_base;
   GLshort v[3];
};
void
_mesa_unmarshal_Color3sv(struct gl_context *ctx, const struct marshal_cmd_Color3sv *cmd)
{
   const GLshort * v = cmd->v;
   CALL_Color3sv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Color3sv(const GLshort * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Color3sv);
   struct marshal_cmd_Color3sv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Color3sv, cmd_size);
   memcpy(cmd->v, v, 3 * sizeof(GLshort));
}


/* Color3ub: marshalled asynchronously */
struct marshal_cmd_Color3ub
{
   struct marshal_cmd_base cmd_base;
   GLubyte red;
   GLubyte green;
   GLubyte blue;
};
void
_mesa_unmarshal_Color3ub(struct gl_context *ctx, const struct marshal_cmd_Color3ub *cmd)
{
   const GLubyte red = cmd->red;
   const GLubyte green = cmd->green;
   const GLubyte blue = cmd->blue;
   CALL_Color3ub(ctx->CurrentServerDispatch, (red, green, blue));
}
void GLAPIENTRY
_mesa_marshal_Color3ub(GLubyte red, GLubyte green, GLubyte blue)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Color3ub);
   struct marshal_cmd_Color3ub *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Color3ub, cmd_size);
   cmd->red = red;
   cmd->green = green;
   cmd->blue = blue;
}


/* Color3ubv: marshalled asynchronously */
struct marshal_cmd_Color3ubv
{
   struct marshal_cmd_base cmd_base;
   GLubyte v[3];
};
void
_mesa_unmarshal_Color3ubv(struct gl_context *ctx, const struct marshal_cmd_Color3ubv *cmd)
{
   const GLubyte * v = cmd->v;
   CALL_Color3ubv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Color3ubv(const GLubyte * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Color3ubv);
   struct marshal_cmd_Color3ubv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Color3ubv, cmd_size);
   memcpy(cmd->v, v, 3 * sizeof(GLubyte));
}


/* Color3ui: marshalled asynchronously */
struct marshal_cmd_Color3ui
{
   struct marshal_cmd_base cmd_base;
   GLuint red;
   GLuint green;
   GLuint blue;
};
void
_mesa_unmarshal_Color3ui(struct gl_context *ctx, const struct marshal_cmd_Color3ui *cmd)
{
   const GLuint red = cmd->red;
   const GLuint green = cmd->green;
   const GLuint blue = cmd->blue;
   CALL_Color3ui(ctx->CurrentServerDispatch, (red, green, blue));
}
void GLAPIENTRY
_mesa_marshal_Color3ui(GLuint red, GLuint green, GLuint blue)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Color3ui);
   struct marshal_cmd_Color3ui *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Color3ui, cmd_size);
   cmd->red = red;
   cmd->green = green;
   cmd->blue = blue;
}


/* Color3uiv: marshalled asynchronously */
struct marshal_cmd_Color3uiv
{
   struct marshal_cmd_base cmd_base;
   GLuint v[3];
};
void
_mesa_unmarshal_Color3uiv(struct gl_context *ctx, const struct marshal_cmd_Color3uiv *cmd)
{
   const GLuint * v = cmd->v;
   CALL_Color3uiv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Color3uiv(const GLuint * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Color3uiv);
   struct marshal_cmd_Color3uiv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Color3uiv, cmd_size);
   memcpy(cmd->v, v, 3 * sizeof(GLuint));
}


/* Color3us: marshalled asynchronously */
struct marshal_cmd_Color3us
{
   struct marshal_cmd_base cmd_base;
   GLushort red;
   GLushort green;
   GLushort blue;
};
void
_mesa_unmarshal_Color3us(struct gl_context *ctx, const struct marshal_cmd_Color3us *cmd)
{
   const GLushort red = cmd->red;
   const GLushort green = cmd->green;
   const GLushort blue = cmd->blue;
   CALL_Color3us(ctx->CurrentServerDispatch, (red, green, blue));
}
void GLAPIENTRY
_mesa_marshal_Color3us(GLushort red, GLushort green, GLushort blue)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Color3us);
   struct marshal_cmd_Color3us *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Color3us, cmd_size);
   cmd->red = red;
   cmd->green = green;
   cmd->blue = blue;
}


/* Color3usv: marshalled asynchronously */
struct marshal_cmd_Color3usv
{
   struct marshal_cmd_base cmd_base;
   GLushort v[3];
};
void
_mesa_unmarshal_Color3usv(struct gl_context *ctx, const struct marshal_cmd_Color3usv *cmd)
{
   const GLushort * v = cmd->v;
   CALL_Color3usv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Color3usv(const GLushort * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Color3usv);
   struct marshal_cmd_Color3usv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Color3usv, cmd_size);
   memcpy(cmd->v, v, 3 * sizeof(GLushort));
}


/* Color4b: marshalled asynchronously */
struct marshal_cmd_Color4b
{
   struct marshal_cmd_base cmd_base;
   GLbyte red;
   GLbyte green;
   GLbyte blue;
   GLbyte alpha;
};
void
_mesa_unmarshal_Color4b(struct gl_context *ctx, const struct marshal_cmd_Color4b *cmd)
{
   const GLbyte red = cmd->red;
   const GLbyte green = cmd->green;
   const GLbyte blue = cmd->blue;
   const GLbyte alpha = cmd->alpha;
   CALL_Color4b(ctx->CurrentServerDispatch, (red, green, blue, alpha));
}
void GLAPIENTRY
_mesa_marshal_Color4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Color4b);
   struct marshal_cmd_Color4b *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Color4b, cmd_size);
   cmd->red = red;
   cmd->green = green;
   cmd->blue = blue;
   cmd->alpha = alpha;
}


/* Color4bv: marshalled asynchronously */
struct marshal_cmd_Color4bv
{
   struct marshal_cmd_base cmd_base;
   GLbyte v[4];
};
void
_mesa_unmarshal_Color4bv(struct gl_context *ctx, const struct marshal_cmd_Color4bv *cmd)
{
   const GLbyte * v = cmd->v;
   CALL_Color4bv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Color4bv(const GLbyte * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Color4bv);
   struct marshal_cmd_Color4bv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Color4bv, cmd_size);
   memcpy(cmd->v, v, 4 * sizeof(GLbyte));
}


/* Color4d: marshalled asynchronously */
struct marshal_cmd_Color4d
{
   struct marshal_cmd_base cmd_base;
   GLdouble red;
   GLdouble green;
   GLdouble blue;
   GLdouble alpha;
};
void
_mesa_unmarshal_Color4d(struct gl_context *ctx, const struct marshal_cmd_Color4d *cmd)
{
   const GLdouble red = cmd->red;
   const GLdouble green = cmd->green;
   const GLdouble blue = cmd->blue;
   const GLdouble alpha = cmd->alpha;
   CALL_Color4d(ctx->CurrentServerDispatch, (red, green, blue, alpha));
}
void GLAPIENTRY
_mesa_marshal_Color4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Color4d);
   struct marshal_cmd_Color4d *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Color4d, cmd_size);
   cmd->red = red;
   cmd->green = green;
   cmd->blue = blue;
   cmd->alpha = alpha;
}


/* Color4dv: marshalled asynchronously */
struct marshal_cmd_Color4dv
{
   struct marshal_cmd_base cmd_base;
   GLdouble v[4];
};
void
_mesa_unmarshal_Color4dv(struct gl_context *ctx, const struct marshal_cmd_Color4dv *cmd)
{
   const GLdouble * v = cmd->v;
   CALL_Color4dv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Color4dv(const GLdouble * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Color4dv);
   struct marshal_cmd_Color4dv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Color4dv, cmd_size);
   memcpy(cmd->v, v, 4 * sizeof(GLdouble));
}


/* Color4f: marshalled asynchronously */
struct marshal_cmd_Color4f
{
   struct marshal_cmd_base cmd_base;
   GLfloat red;
   GLfloat green;
   GLfloat blue;
   GLfloat alpha;
};
void
_mesa_unmarshal_Color4f(struct gl_context *ctx, const struct marshal_cmd_Color4f *cmd)
{
   const GLfloat red = cmd->red;
   const GLfloat green = cmd->green;
   const GLfloat blue = cmd->blue;
   const GLfloat alpha = cmd->alpha;
   CALL_Color4f(ctx->CurrentServerDispatch, (red, green, blue, alpha));
}
void GLAPIENTRY
_mesa_marshal_Color4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Color4f);
   struct marshal_cmd_Color4f *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Color4f, cmd_size);
   cmd->red = red;
   cmd->green = green;
   cmd->blue = blue;
   cmd->alpha = alpha;
}


/* Color4fv: marshalled asynchronously */
struct marshal_cmd_Color4fv
{
   struct marshal_cmd_base cmd_base;
   GLfloat v[4];
};
void
_mesa_unmarshal_Color4fv(struct gl_context *ctx, const struct marshal_cmd_Color4fv *cmd)
{
   const GLfloat * v = cmd->v;
   CALL_Color4fv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Color4fv(const GLfloat * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Color4fv);
   struct marshal_cmd_Color4fv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Color4fv, cmd_size);
   memcpy(cmd->v, v, 4 * sizeof(GLfloat));
}


/* Color4i: marshalled asynchronously */
struct marshal_cmd_Color4i
{
   struct marshal_cmd_base cmd_base;
   GLint red;
   GLint green;
   GLint blue;
   GLint alpha;
};
void
_mesa_unmarshal_Color4i(struct gl_context *ctx, const struct marshal_cmd_Color4i *cmd)
{
   const GLint red = cmd->red;
   const GLint green = cmd->green;
   const GLint blue = cmd->blue;
   const GLint alpha = cmd->alpha;
   CALL_Color4i(ctx->CurrentServerDispatch, (red, green, blue, alpha));
}
void GLAPIENTRY
_mesa_marshal_Color4i(GLint red, GLint green, GLint blue, GLint alpha)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Color4i);
   struct marshal_cmd_Color4i *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Color4i, cmd_size);
   cmd->red = red;
   cmd->green = green;
   cmd->blue = blue;
   cmd->alpha = alpha;
}


/* Color4iv: marshalled asynchronously */
struct marshal_cmd_Color4iv
{
   struct marshal_cmd_base cmd_base;
   GLint v[4];
};
void
_mesa_unmarshal_Color4iv(struct gl_context *ctx, const struct marshal_cmd_Color4iv *cmd)
{
   const GLint * v = cmd->v;
   CALL_Color4iv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Color4iv(const GLint * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Color4iv);
   struct marshal_cmd_Color4iv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Color4iv, cmd_size);
   memcpy(cmd->v, v, 4 * sizeof(GLint));
}


/* Color4s: marshalled asynchronously */
struct marshal_cmd_Color4s
{
   struct marshal_cmd_base cmd_base;
   GLshort red;
   GLshort green;
   GLshort blue;
   GLshort alpha;
};
void
_mesa_unmarshal_Color4s(struct gl_context *ctx, const struct marshal_cmd_Color4s *cmd)
{
   const GLshort red = cmd->red;
   const GLshort green = cmd->green;
   const GLshort blue = cmd->blue;
   const GLshort alpha = cmd->alpha;
   CALL_Color4s(ctx->CurrentServerDispatch, (red, green, blue, alpha));
}
void GLAPIENTRY
_mesa_marshal_Color4s(GLshort red, GLshort green, GLshort blue, GLshort alpha)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Color4s);
   struct marshal_cmd_Color4s *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Color4s, cmd_size);
   cmd->red = red;
   cmd->green = green;
   cmd->blue = blue;
   cmd->alpha = alpha;
}


/* Color4sv: marshalled asynchronously */
struct marshal_cmd_Color4sv
{
   struct marshal_cmd_base cmd_base;
   GLshort v[4];
};
void
_mesa_unmarshal_Color4sv(struct gl_context *ctx, const struct marshal_cmd_Color4sv *cmd)
{
   const GLshort * v = cmd->v;
   CALL_Color4sv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Color4sv(const GLshort * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Color4sv);
   struct marshal_cmd_Color4sv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Color4sv, cmd_size);
   memcpy(cmd->v, v, 4 * sizeof(GLshort));
}


/* Color4ub: marshalled asynchronously */
struct marshal_cmd_Color4ub
{
   struct marshal_cmd_base cmd_base;
   GLubyte red;
   GLubyte green;
   GLubyte blue;
   GLubyte alpha;
};
void
_mesa_unmarshal_Color4ub(struct gl_context *ctx, const struct marshal_cmd_Color4ub *cmd)
{
   const GLubyte red = cmd->red;
   const GLubyte green = cmd->green;
   const GLubyte blue = cmd->blue;
   const GLubyte alpha = cmd->alpha;
   CALL_Color4ub(ctx->CurrentServerDispatch, (red, green, blue, alpha));
}
void GLAPIENTRY
_mesa_marshal_Color4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Color4ub);
   struct marshal_cmd_Color4ub *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Color4ub, cmd_size);
   cmd->red = red;
   cmd->green = green;
   cmd->blue = blue;
   cmd->alpha = alpha;
}


/* Color4ubv: marshalled asynchronously */
struct marshal_cmd_Color4ubv
{
   struct marshal_cmd_base cmd_base;
   GLubyte v[4];
};
void
_mesa_unmarshal_Color4ubv(struct gl_context *ctx, const struct marshal_cmd_Color4ubv *cmd)
{
   const GLubyte * v = cmd->v;
   CALL_Color4ubv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Color4ubv(const GLubyte * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Color4ubv);
   struct marshal_cmd_Color4ubv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Color4ubv, cmd_size);
   memcpy(cmd->v, v, 4 * sizeof(GLubyte));
}


/* Color4ui: marshalled asynchronously */
struct marshal_cmd_Color4ui
{
   struct marshal_cmd_base cmd_base;
   GLuint red;
   GLuint green;
   GLuint blue;
   GLuint alpha;
};
void
_mesa_unmarshal_Color4ui(struct gl_context *ctx, const struct marshal_cmd_Color4ui *cmd)
{
   const GLuint red = cmd->red;
   const GLuint green = cmd->green;
   const GLuint blue = cmd->blue;
   const GLuint alpha = cmd->alpha;
   CALL_Color4ui(ctx->CurrentServerDispatch, (red, green, blue, alpha));
}
void GLAPIENTRY
_mesa_marshal_Color4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Color4ui);
   struct marshal_cmd_Color4ui *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Color4ui, cmd_size);
   cmd->red = red;
   cmd->green = green;
   cmd->blue = blue;
   cmd->alpha = alpha;
}


/* Color4uiv: marshalled asynchronously */
struct marshal_cmd_Color4uiv
{
   struct marshal_cmd_base cmd_base;
   GLuint v[4];
};
void
_mesa_unmarshal_Color4uiv(struct gl_context *ctx, const struct marshal_cmd_Color4uiv *cmd)
{
   const GLuint * v = cmd->v;
   CALL_Color4uiv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Color4uiv(const GLuint * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Color4uiv);
   struct marshal_cmd_Color4uiv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Color4uiv, cmd_size);
   memcpy(cmd->v, v, 4 * sizeof(GLuint));
}


/* Color4us: marshalled asynchronously */
struct marshal_cmd_Color4us
{
   struct marshal_cmd_base cmd_base;
   GLushort red;
   GLushort green;
   GLushort blue;
   GLushort alpha;
};
void
_mesa_unmarshal_Color4us(struct gl_context *ctx, const struct marshal_cmd_Color4us *cmd)
{
   const GLushort red = cmd->red;
   const GLushort green = cmd->green;
   const GLushort blue = cmd->blue;
   const GLushort alpha = cmd->alpha;
   CALL_Color4us(ctx->CurrentServerDispatch, (red, green, blue, alpha));
}
void GLAPIENTRY
_mesa_marshal_Color4us(GLushort red, GLushort green, GLushort blue, GLushort alpha)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Color4us);
   struct marshal_cmd_Color4us *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Color4us, cmd_size);
   cmd->red = red;
   cmd->green = green;
   cmd->blue = blue;
   cmd->alpha = alpha;
}


/* Color4usv: marshalled asynchronously */
struct marshal_cmd_Color4usv
{
   struct marshal_cmd_base cmd_base;
   GLushort v[4];
};
void
_mesa_unmarshal_Color4usv(struct gl_context *ctx, const struct marshal_cmd_Color4usv *cmd)
{
   const GLushort * v = cmd->v;
   CALL_Color4usv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Color4usv(const GLushort * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Color4usv);
   struct marshal_cmd_Color4usv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Color4usv, cmd_size);
   memcpy(cmd->v, v, 4 * sizeof(GLushort));
}


/* EdgeFlag: marshalled asynchronously */
struct marshal_cmd_EdgeFlag
{
   struct marshal_cmd_base cmd_base;
   GLboolean flag;
};
void
_mesa_unmarshal_EdgeFlag(struct gl_context *ctx, const struct marshal_cmd_EdgeFlag *cmd)
{
   const GLboolean flag = cmd->flag;
   CALL_EdgeFlag(ctx->CurrentServerDispatch, (flag));
}
void GLAPIENTRY
_mesa_marshal_EdgeFlag(GLboolean flag)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_EdgeFlag);
   struct marshal_cmd_EdgeFlag *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_EdgeFlag, cmd_size);
   cmd->flag = flag;
}


/* EdgeFlagv: marshalled asynchronously */
struct marshal_cmd_EdgeFlagv
{
   struct marshal_cmd_base cmd_base;
   GLboolean flag[1];
};
void
_mesa_unmarshal_EdgeFlagv(struct gl_context *ctx, const struct marshal_cmd_EdgeFlagv *cmd)
{
   const GLboolean * flag = cmd->flag;
   CALL_EdgeFlagv(ctx->CurrentServerDispatch, (flag));
}
void GLAPIENTRY
_mesa_marshal_EdgeFlagv(const GLboolean * flag)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_EdgeFlagv);
   struct marshal_cmd_EdgeFlagv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_EdgeFlagv, cmd_size);
   memcpy(cmd->flag, flag, 1 * sizeof(GLboolean));
}


/* End: marshalled asynchronously */
struct marshal_cmd_End
{
   struct marshal_cmd_base cmd_base;
};
void
_mesa_unmarshal_End(struct gl_context *ctx, const struct marshal_cmd_End *cmd)
{
   CALL_End(ctx->CurrentServerDispatch, ());
}
void GLAPIENTRY
_mesa_marshal_End(void)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_End);
   struct marshal_cmd_End *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_End, cmd_size);
   (void) cmd;
}


/* Indexd: marshalled asynchronously */
struct marshal_cmd_Indexd
{
   struct marshal_cmd_base cmd_base;
   GLdouble c;
};
void
_mesa_unmarshal_Indexd(struct gl_context *ctx, const struct marshal_cmd_Indexd *cmd)
{
   const GLdouble c = cmd->c;
   CALL_Indexd(ctx->CurrentServerDispatch, (c));
}
void GLAPIENTRY
_mesa_marshal_Indexd(GLdouble c)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Indexd);
   struct marshal_cmd_Indexd *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Indexd, cmd_size);
   cmd->c = c;
}


/* Indexdv: marshalled asynchronously */
struct marshal_cmd_Indexdv
{
   struct marshal_cmd_base cmd_base;
   GLdouble c[1];
};
void
_mesa_unmarshal_Indexdv(struct gl_context *ctx, const struct marshal_cmd_Indexdv *cmd)
{
   const GLdouble * c = cmd->c;
   CALL_Indexdv(ctx->CurrentServerDispatch, (c));
}
void GLAPIENTRY
_mesa_marshal_Indexdv(const GLdouble * c)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Indexdv);
   struct marshal_cmd_Indexdv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Indexdv, cmd_size);
   memcpy(cmd->c, c, 1 * sizeof(GLdouble));
}


/* Indexf: marshalled asynchronously */
struct marshal_cmd_Indexf
{
   struct marshal_cmd_base cmd_base;
   GLfloat c;
};
void
_mesa_unmarshal_Indexf(struct gl_context *ctx, const struct marshal_cmd_Indexf *cmd)
{
   const GLfloat c = cmd->c;
   CALL_Indexf(ctx->CurrentServerDispatch, (c));
}
void GLAPIENTRY
_mesa_marshal_Indexf(GLfloat c)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Indexf);
   struct marshal_cmd_Indexf *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Indexf, cmd_size);
   cmd->c = c;
}


/* Indexfv: marshalled asynchronously */
struct marshal_cmd_Indexfv
{
   struct marshal_cmd_base cmd_base;
   GLfloat c[1];
};
void
_mesa_unmarshal_Indexfv(struct gl_context *ctx, const struct marshal_cmd_Indexfv *cmd)
{
   const GLfloat * c = cmd->c;
   CALL_Indexfv(ctx->CurrentServerDispatch, (c));
}
void GLAPIENTRY
_mesa_marshal_Indexfv(const GLfloat * c)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Indexfv);
   struct marshal_cmd_Indexfv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Indexfv, cmd_size);
   memcpy(cmd->c, c, 1 * sizeof(GLfloat));
}


/* Indexi: marshalled asynchronously */
struct marshal_cmd_Indexi
{
   struct marshal_cmd_base cmd_base;
   GLint c;
};
void
_mesa_unmarshal_Indexi(struct gl_context *ctx, const struct marshal_cmd_Indexi *cmd)
{
   const GLint c = cmd->c;
   CALL_Indexi(ctx->CurrentServerDispatch, (c));
}
void GLAPIENTRY
_mesa_marshal_Indexi(GLint c)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Indexi);
   struct marshal_cmd_Indexi *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Indexi, cmd_size);
   cmd->c = c;
}


/* Indexiv: marshalled asynchronously */
struct marshal_cmd_Indexiv
{
   struct marshal_cmd_base cmd_base;
   GLint c[1];
};
void
_mesa_unmarshal_Indexiv(struct gl_context *ctx, const struct marshal_cmd_Indexiv *cmd)
{
   const GLint * c = cmd->c;
   CALL_Indexiv(ctx->CurrentServerDispatch, (c));
}
void GLAPIENTRY
_mesa_marshal_Indexiv(const GLint * c)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Indexiv);
   struct marshal_cmd_Indexiv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Indexiv, cmd_size);
   memcpy(cmd->c, c, 1 * sizeof(GLint));
}


/* Indexs: marshalled asynchronously */
struct marshal_cmd_Indexs
{
   struct marshal_cmd_base cmd_base;
   GLshort c;
};
void
_mesa_unmarshal_Indexs(struct gl_context *ctx, const struct marshal_cmd_Indexs *cmd)
{
   const GLshort c = cmd->c;
   CALL_Indexs(ctx->CurrentServerDispatch, (c));
}
void GLAPIENTRY
_mesa_marshal_Indexs(GLshort c)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Indexs);
   struct marshal_cmd_Indexs *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Indexs, cmd_size);
   cmd->c = c;
}


/* Indexsv: marshalled asynchronously */
struct marshal_cmd_Indexsv
{
   struct marshal_cmd_base cmd_base;
   GLshort c[1];
};
void
_mesa_unmarshal_Indexsv(struct gl_context *ctx, const struct marshal_cmd_Indexsv *cmd)
{
   const GLshort * c = cmd->c;
   CALL_Indexsv(ctx->CurrentServerDispatch, (c));
}
void GLAPIENTRY
_mesa_marshal_Indexsv(const GLshort * c)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Indexsv);
   struct marshal_cmd_Indexsv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Indexsv, cmd_size);
   memcpy(cmd->c, c, 1 * sizeof(GLshort));
}


/* Normal3b: marshalled asynchronously */
struct marshal_cmd_Normal3b
{
   struct marshal_cmd_base cmd_base;
   GLbyte nx;
   GLbyte ny;
   GLbyte nz;
};
void
_mesa_unmarshal_Normal3b(struct gl_context *ctx, const struct marshal_cmd_Normal3b *cmd)
{
   const GLbyte nx = cmd->nx;
   const GLbyte ny = cmd->ny;
   const GLbyte nz = cmd->nz;
   CALL_Normal3b(ctx->CurrentServerDispatch, (nx, ny, nz));
}
void GLAPIENTRY
_mesa_marshal_Normal3b(GLbyte nx, GLbyte ny, GLbyte nz)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Normal3b);
   struct marshal_cmd_Normal3b *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Normal3b, cmd_size);
   cmd->nx = nx;
   cmd->ny = ny;
   cmd->nz = nz;
}


/* Normal3bv: marshalled asynchronously */
struct marshal_cmd_Normal3bv
{
   struct marshal_cmd_base cmd_base;
   GLbyte v[3];
};
void
_mesa_unmarshal_Normal3bv(struct gl_context *ctx, const struct marshal_cmd_Normal3bv *cmd)
{
   const GLbyte * v = cmd->v;
   CALL_Normal3bv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Normal3bv(const GLbyte * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Normal3bv);
   struct marshal_cmd_Normal3bv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Normal3bv, cmd_size);
   memcpy(cmd->v, v, 3 * sizeof(GLbyte));
}


/* Normal3d: marshalled asynchronously */
struct marshal_cmd_Normal3d
{
   struct marshal_cmd_base cmd_base;
   GLdouble nx;
   GLdouble ny;
   GLdouble nz;
};
void
_mesa_unmarshal_Normal3d(struct gl_context *ctx, const struct marshal_cmd_Normal3d *cmd)
{
   const GLdouble nx = cmd->nx;
   const GLdouble ny = cmd->ny;
   const GLdouble nz = cmd->nz;
   CALL_Normal3d(ctx->CurrentServerDispatch, (nx, ny, nz));
}
void GLAPIENTRY
_mesa_marshal_Normal3d(GLdouble nx, GLdouble ny, GLdouble nz)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Normal3d);
   struct marshal_cmd_Normal3d *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Normal3d, cmd_size);
   cmd->nx = nx;
   cmd->ny = ny;
   cmd->nz = nz;
}


/* Normal3dv: marshalled asynchronously */
struct marshal_cmd_Normal3dv
{
   struct marshal_cmd_base cmd_base;
   GLdouble v[3];
};
void
_mesa_unmarshal_Normal3dv(struct gl_context *ctx, const struct marshal_cmd_Normal3dv *cmd)
{
   const GLdouble * v = cmd->v;
   CALL_Normal3dv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Normal3dv(const GLdouble * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Normal3dv);
   struct marshal_cmd_Normal3dv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Normal3dv, cmd_size);
   memcpy(cmd->v, v, 3 * sizeof(GLdouble));
}


/* Normal3f: marshalled asynchronously */
struct marshal_cmd_Normal3f
{
   struct marshal_cmd_base cmd_base;
   GLfloat nx;
   GLfloat ny;
   GLfloat nz;
};
void
_mesa_unmarshal_Normal3f(struct gl_context *ctx, const struct marshal_cmd_Normal3f *cmd)
{
   const GLfloat nx = cmd->nx;
   const GLfloat ny = cmd->ny;
   const GLfloat nz = cmd->nz;
   CALL_Normal3f(ctx->CurrentServerDispatch, (nx, ny, nz));
}
void GLAPIENTRY
_mesa_marshal_Normal3f(GLfloat nx, GLfloat ny, GLfloat nz)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Normal3f);
   struct marshal_cmd_Normal3f *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Normal3f, cmd_size);
   cmd->nx = nx;
   cmd->ny = ny;
   cmd->nz = nz;
}


/* Normal3fv: marshalled asynchronously */
struct marshal_cmd_Normal3fv
{
   struct marshal_cmd_base cmd_base;
   GLfloat v[3];
};
void
_mesa_unmarshal_Normal3fv(struct gl_context *ctx, const struct marshal_cmd_Normal3fv *cmd)
{
   const GLfloat * v = cmd->v;
   CALL_Normal3fv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Normal3fv(const GLfloat * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Normal3fv);
   struct marshal_cmd_Normal3fv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Normal3fv, cmd_size);
   memcpy(cmd->v, v, 3 * sizeof(GLfloat));
}


/* Normal3i: marshalled asynchronously */
struct marshal_cmd_Normal3i
{
   struct marshal_cmd_base cmd_base;
   GLint nx;
   GLint ny;
   GLint nz;
};
void
_mesa_unmarshal_Normal3i(struct gl_context *ctx, const struct marshal_cmd_Normal3i *cmd)
{
   const GLint nx = cmd->nx;
   const GLint ny = cmd->ny;
   const GLint nz = cmd->nz;
   CALL_Normal3i(ctx->CurrentServerDispatch, (nx, ny, nz));
}
void GLAPIENTRY
_mesa_marshal_Normal3i(GLint nx, GLint ny, GLint nz)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Normal3i);
   struct marshal_cmd_Normal3i *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Normal3i, cmd_size);
   cmd->nx = nx;
   cmd->ny = ny;
   cmd->nz = nz;
}


/* Normal3iv: marshalled asynchronously */
struct marshal_cmd_Normal3iv
{
   struct marshal_cmd_base cmd_base;
   GLint v[3];
};
void
_mesa_unmarshal_Normal3iv(struct gl_context *ctx, const struct marshal_cmd_Normal3iv *cmd)
{
   const GLint * v = cmd->v;
   CALL_Normal3iv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Normal3iv(const GLint * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Normal3iv);
   struct marshal_cmd_Normal3iv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Normal3iv, cmd_size);
   memcpy(cmd->v, v, 3 * sizeof(GLint));
}


/* Normal3s: marshalled asynchronously */
struct marshal_cmd_Normal3s
{
   struct marshal_cmd_base cmd_base;
   GLshort nx;
   GLshort ny;
   GLshort nz;
};
void
_mesa_unmarshal_Normal3s(struct gl_context *ctx, const struct marshal_cmd_Normal3s *cmd)
{
   const GLshort nx = cmd->nx;
   const GLshort ny = cmd->ny;
   const GLshort nz = cmd->nz;
   CALL_Normal3s(ctx->CurrentServerDispatch, (nx, ny, nz));
}
void GLAPIENTRY
_mesa_marshal_Normal3s(GLshort nx, GLshort ny, GLshort nz)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Normal3s);
   struct marshal_cmd_Normal3s *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Normal3s, cmd_size);
   cmd->nx = nx;
   cmd->ny = ny;
   cmd->nz = nz;
}


/* Normal3sv: marshalled asynchronously */
struct marshal_cmd_Normal3sv
{
   struct marshal_cmd_base cmd_base;
   GLshort v[3];
};
void
_mesa_unmarshal_Normal3sv(struct gl_context *ctx, const struct marshal_cmd_Normal3sv *cmd)
{
   const GLshort * v = cmd->v;
   CALL_Normal3sv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Normal3sv(const GLshort * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Normal3sv);
   struct marshal_cmd_Normal3sv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Normal3sv, cmd_size);
   memcpy(cmd->v, v, 3 * sizeof(GLshort));
}


/* RasterPos2d: marshalled asynchronously */
struct marshal_cmd_RasterPos2d
{
   struct marshal_cmd_base cmd_base;
   GLdouble x;
   GLdouble y;
};
void
_mesa_unmarshal_RasterPos2d(struct gl_context *ctx, const struct marshal_cmd_RasterPos2d *cmd)
{
   const GLdouble x = cmd->x;
   const GLdouble y = cmd->y;
   CALL_RasterPos2d(ctx->CurrentServerDispatch, (x, y));
}
void GLAPIENTRY
_mesa_marshal_RasterPos2d(GLdouble x, GLdouble y)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_RasterPos2d);
   struct marshal_cmd_RasterPos2d *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_RasterPos2d, cmd_size);
   cmd->x = x;
   cmd->y = y;
}


/* RasterPos2dv: marshalled asynchronously */
struct marshal_cmd_RasterPos2dv
{
   struct marshal_cmd_base cmd_base;
   GLdouble v[2];
};
void
_mesa_unmarshal_RasterPos2dv(struct gl_context *ctx, const struct marshal_cmd_RasterPos2dv *cmd)
{
   const GLdouble * v = cmd->v;
   CALL_RasterPos2dv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_RasterPos2dv(const GLdouble * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_RasterPos2dv);
   struct marshal_cmd_RasterPos2dv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_RasterPos2dv, cmd_size);
   memcpy(cmd->v, v, 2 * sizeof(GLdouble));
}


/* RasterPos2f: marshalled asynchronously */
struct marshal_cmd_RasterPos2f
{
   struct marshal_cmd_base cmd_base;
   GLfloat x;
   GLfloat y;
};
void
_mesa_unmarshal_RasterPos2f(struct gl_context *ctx, const struct marshal_cmd_RasterPos2f *cmd)
{
   const GLfloat x = cmd->x;
   const GLfloat y = cmd->y;
   CALL_RasterPos2f(ctx->CurrentServerDispatch, (x, y));
}
void GLAPIENTRY
_mesa_marshal_RasterPos2f(GLfloat x, GLfloat y)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_RasterPos2f);
   struct marshal_cmd_RasterPos2f *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_RasterPos2f, cmd_size);
   cmd->x = x;
   cmd->y = y;
}


/* RasterPos2fv: marshalled asynchronously */
struct marshal_cmd_RasterPos2fv
{
   struct marshal_cmd_base cmd_base;
   GLfloat v[2];
};
void
_mesa_unmarshal_RasterPos2fv(struct gl_context *ctx, const struct marshal_cmd_RasterPos2fv *cmd)
{
   const GLfloat * v = cmd->v;
   CALL_RasterPos2fv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_RasterPos2fv(const GLfloat * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_RasterPos2fv);
   struct marshal_cmd_RasterPos2fv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_RasterPos2fv, cmd_size);
   memcpy(cmd->v, v, 2 * sizeof(GLfloat));
}


/* RasterPos2i: marshalled asynchronously */
struct marshal_cmd_RasterPos2i
{
   struct marshal_cmd_base cmd_base;
   GLint x;
   GLint y;
};
void
_mesa_unmarshal_RasterPos2i(struct gl_context *ctx, const struct marshal_cmd_RasterPos2i *cmd)
{
   const GLint x = cmd->x;
   const GLint y = cmd->y;
   CALL_RasterPos2i(ctx->CurrentServerDispatch, (x, y));
}
void GLAPIENTRY
_mesa_marshal_RasterPos2i(GLint x, GLint y)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_RasterPos2i);
   struct marshal_cmd_RasterPos2i *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_RasterPos2i, cmd_size);
   cmd->x = x;
   cmd->y = y;
}


/* RasterPos2iv: marshalled asynchronously */
struct marshal_cmd_RasterPos2iv
{
   struct marshal_cmd_base cmd_base;
   GLint v[2];
};
void
_mesa_unmarshal_RasterPos2iv(struct gl_context *ctx, const struct marshal_cmd_RasterPos2iv *cmd)
{
   const GLint * v = cmd->v;
   CALL_RasterPos2iv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_RasterPos2iv(const GLint * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_RasterPos2iv);
   struct marshal_cmd_RasterPos2iv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_RasterPos2iv, cmd_size);
   memcpy(cmd->v, v, 2 * sizeof(GLint));
}


/* RasterPos2s: marshalled asynchronously */
struct marshal_cmd_RasterPos2s
{
   struct marshal_cmd_base cmd_base;
   GLshort x;
   GLshort y;
};
void
_mesa_unmarshal_RasterPos2s(struct gl_context *ctx, const struct marshal_cmd_RasterPos2s *cmd)
{
   const GLshort x = cmd->x;
   const GLshort y = cmd->y;
   CALL_RasterPos2s(ctx->CurrentServerDispatch, (x, y));
}
void GLAPIENTRY
_mesa_marshal_RasterPos2s(GLshort x, GLshort y)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_RasterPos2s);
   struct marshal_cmd_RasterPos2s *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_RasterPos2s, cmd_size);
   cmd->x = x;
   cmd->y = y;
}


/* RasterPos2sv: marshalled asynchronously */
struct marshal_cmd_RasterPos2sv
{
   struct marshal_cmd_base cmd_base;
   GLshort v[2];
};
void
_mesa_unmarshal_RasterPos2sv(struct gl_context *ctx, const struct marshal_cmd_RasterPos2sv *cmd)
{
   const GLshort * v = cmd->v;
   CALL_RasterPos2sv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_RasterPos2sv(const GLshort * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_RasterPos2sv);
   struct marshal_cmd_RasterPos2sv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_RasterPos2sv, cmd_size);
   memcpy(cmd->v, v, 2 * sizeof(GLshort));
}


/* RasterPos3d: marshalled asynchronously */
struct marshal_cmd_RasterPos3d
{
   struct marshal_cmd_base cmd_base;
   GLdouble x;
   GLdouble y;
   GLdouble z;
};
void
_mesa_unmarshal_RasterPos3d(struct gl_context *ctx, const struct marshal_cmd_RasterPos3d *cmd)
{
   const GLdouble x = cmd->x;
   const GLdouble y = cmd->y;
   const GLdouble z = cmd->z;
   CALL_RasterPos3d(ctx->CurrentServerDispatch, (x, y, z));
}
void GLAPIENTRY
_mesa_marshal_RasterPos3d(GLdouble x, GLdouble y, GLdouble z)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_RasterPos3d);
   struct marshal_cmd_RasterPos3d *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_RasterPos3d, cmd_size);
   cmd->x = x;
   cmd->y = y;
   cmd->z = z;
}


/* RasterPos3dv: marshalled asynchronously */
struct marshal_cmd_RasterPos3dv
{
   struct marshal_cmd_base cmd_base;
   GLdouble v[3];
};
void
_mesa_unmarshal_RasterPos3dv(struct gl_context *ctx, const struct marshal_cmd_RasterPos3dv *cmd)
{
   const GLdouble * v = cmd->v;
   CALL_RasterPos3dv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_RasterPos3dv(const GLdouble * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_RasterPos3dv);
   struct marshal_cmd_RasterPos3dv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_RasterPos3dv, cmd_size);
   memcpy(cmd->v, v, 3 * sizeof(GLdouble));
}


/* RasterPos3f: marshalled asynchronously */
struct marshal_cmd_RasterPos3f
{
   struct marshal_cmd_base cmd_base;
   GLfloat x;
   GLfloat y;
   GLfloat z;
};
void
_mesa_unmarshal_RasterPos3f(struct gl_context *ctx, const struct marshal_cmd_RasterPos3f *cmd)
{
   const GLfloat x = cmd->x;
   const GLfloat y = cmd->y;
   const GLfloat z = cmd->z;
   CALL_RasterPos3f(ctx->CurrentServerDispatch, (x, y, z));
}
void GLAPIENTRY
_mesa_marshal_RasterPos3f(GLfloat x, GLfloat y, GLfloat z)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_RasterPos3f);
   struct marshal_cmd_RasterPos3f *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_RasterPos3f, cmd_size);
   cmd->x = x;
   cmd->y = y;
   cmd->z = z;
}


/* RasterPos3fv: marshalled asynchronously */
struct marshal_cmd_RasterPos3fv
{
   struct marshal_cmd_base cmd_base;
   GLfloat v[3];
};
void
_mesa_unmarshal_RasterPos3fv(struct gl_context *ctx, const struct marshal_cmd_RasterPos3fv *cmd)
{
   const GLfloat * v = cmd->v;
   CALL_RasterPos3fv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_RasterPos3fv(const GLfloat * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_RasterPos3fv);
   struct marshal_cmd_RasterPos3fv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_RasterPos3fv, cmd_size);
   memcpy(cmd->v, v, 3 * sizeof(GLfloat));
}


/* RasterPos3i: marshalled asynchronously */
struct marshal_cmd_RasterPos3i
{
   struct marshal_cmd_base cmd_base;
   GLint x;
   GLint y;
   GLint z;
};
void
_mesa_unmarshal_RasterPos3i(struct gl_context *ctx, const struct marshal_cmd_RasterPos3i *cmd)
{
   const GLint x = cmd->x;
   const GLint y = cmd->y;
   const GLint z = cmd->z;
   CALL_RasterPos3i(ctx->CurrentServerDispatch, (x, y, z));
}
void GLAPIENTRY
_mesa_marshal_RasterPos3i(GLint x, GLint y, GLint z)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_RasterPos3i);
   struct marshal_cmd_RasterPos3i *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_RasterPos3i, cmd_size);
   cmd->x = x;
   cmd->y = y;
   cmd->z = z;
}


/* RasterPos3iv: marshalled asynchronously */
struct marshal_cmd_RasterPos3iv
{
   struct marshal_cmd_base cmd_base;
   GLint v[3];
};
void
_mesa_unmarshal_RasterPos3iv(struct gl_context *ctx, const struct marshal_cmd_RasterPos3iv *cmd)
{
   const GLint * v = cmd->v;
   CALL_RasterPos3iv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_RasterPos3iv(const GLint * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_RasterPos3iv);
   struct marshal_cmd_RasterPos3iv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_RasterPos3iv, cmd_size);
   memcpy(cmd->v, v, 3 * sizeof(GLint));
}


/* RasterPos3s: marshalled asynchronously */
struct marshal_cmd_RasterPos3s
{
   struct marshal_cmd_base cmd_base;
   GLshort x;
   GLshort y;
   GLshort z;
};
void
_mesa_unmarshal_RasterPos3s(struct gl_context *ctx, const struct marshal_cmd_RasterPos3s *cmd)
{
   const GLshort x = cmd->x;
   const GLshort y = cmd->y;
   const GLshort z = cmd->z;
   CALL_RasterPos3s(ctx->CurrentServerDispatch, (x, y, z));
}
void GLAPIENTRY
_mesa_marshal_RasterPos3s(GLshort x, GLshort y, GLshort z)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_RasterPos3s);
   struct marshal_cmd_RasterPos3s *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_RasterPos3s, cmd_size);
   cmd->x = x;
   cmd->y = y;
   cmd->z = z;
}


/* RasterPos3sv: marshalled asynchronously */
struct marshal_cmd_RasterPos3sv
{
   struct marshal_cmd_base cmd_base;
   GLshort v[3];
};
void
_mesa_unmarshal_RasterPos3sv(struct gl_context *ctx, const struct marshal_cmd_RasterPos3sv *cmd)
{
   const GLshort * v = cmd->v;
   CALL_RasterPos3sv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_RasterPos3sv(const GLshort * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_RasterPos3sv);
   struct marshal_cmd_RasterPos3sv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_RasterPos3sv, cmd_size);
   memcpy(cmd->v, v, 3 * sizeof(GLshort));
}


/* RasterPos4d: marshalled asynchronously */
struct marshal_cmd_RasterPos4d
{
   struct marshal_cmd_base cmd_base;
   GLdouble x;
   GLdouble y;
   GLdouble z;
   GLdouble w;
};
void
_mesa_unmarshal_RasterPos4d(struct gl_context *ctx, const struct marshal_cmd_RasterPos4d *cmd)
{
   const GLdouble x = cmd->x;
   const GLdouble y = cmd->y;
   const GLdouble z = cmd->z;
   const GLdouble w = cmd->w;
   CALL_RasterPos4d(ctx->CurrentServerDispatch, (x, y, z, w));
}
void GLAPIENTRY
_mesa_marshal_RasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_RasterPos4d);
   struct marshal_cmd_RasterPos4d *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_RasterPos4d, cmd_size);
   cmd->x = x;
   cmd->y = y;
   cmd->z = z;
   cmd->w = w;
}


/* RasterPos4dv: marshalled asynchronously */
struct marshal_cmd_RasterPos4dv
{
   struct marshal_cmd_base cmd_base;
   GLdouble v[4];
};
void
_mesa_unmarshal_RasterPos4dv(struct gl_context *ctx, const struct marshal_cmd_RasterPos4dv *cmd)
{
   const GLdouble * v = cmd->v;
   CALL_RasterPos4dv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_RasterPos4dv(const GLdouble * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_RasterPos4dv);
   struct marshal_cmd_RasterPos4dv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_RasterPos4dv, cmd_size);
   memcpy(cmd->v, v, 4 * sizeof(GLdouble));
}


/* RasterPos4f: marshalled asynchronously */
struct marshal_cmd_RasterPos4f
{
   struct marshal_cmd_base cmd_base;
   GLfloat x;
   GLfloat y;
   GLfloat z;
   GLfloat w;
};
void
_mesa_unmarshal_RasterPos4f(struct gl_context *ctx, const struct marshal_cmd_RasterPos4f *cmd)
{
   const GLfloat x = cmd->x;
   const GLfloat y = cmd->y;
   const GLfloat z = cmd->z;
   const GLfloat w = cmd->w;
   CALL_RasterPos4f(ctx->CurrentServerDispatch, (x, y, z, w));
}
void GLAPIENTRY
_mesa_marshal_RasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_RasterPos4f);
   struct marshal_cmd_RasterPos4f *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_RasterPos4f, cmd_size);
   cmd->x = x;
   cmd->y = y;
   cmd->z = z;
   cmd->w = w;
}


/* RasterPos4fv: marshalled asynchronously */
struct marshal_cmd_RasterPos4fv
{
   struct marshal_cmd_base cmd_base;
   GLfloat v[4];
};
void
_mesa_unmarshal_RasterPos4fv(struct gl_context *ctx, const struct marshal_cmd_RasterPos4fv *cmd)
{
   const GLfloat * v = cmd->v;
   CALL_RasterPos4fv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_RasterPos4fv(const GLfloat * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_RasterPos4fv);
   struct marshal_cmd_RasterPos4fv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_RasterPos4fv, cmd_size);
   memcpy(cmd->v, v, 4 * sizeof(GLfloat));
}


/* RasterPos4i: marshalled asynchronously */
struct marshal_cmd_RasterPos4i
{
   struct marshal_cmd_base cmd_base;
   GLint x;
   GLint y;
   GLint z;
   GLint w;
};
void
_mesa_unmarshal_RasterPos4i(struct gl_context *ctx, const struct marshal_cmd_RasterPos4i *cmd)
{
   const GLint x = cmd->x;
   const GLint y = cmd->y;
   const GLint z = cmd->z;
   const GLint w = cmd->w;
   CALL_RasterPos4i(ctx->CurrentServerDispatch, (x, y, z, w));
}
void GLAPIENTRY
_mesa_marshal_RasterPos4i(GLint x, GLint y, GLint z, GLint w)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_RasterPos4i);
   struct marshal_cmd_RasterPos4i *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_RasterPos4i, cmd_size);
   cmd->x = x;
   cmd->y = y;
   cmd->z = z;
   cmd->w = w;
}


/* RasterPos4iv: marshalled asynchronously */
struct marshal_cmd_RasterPos4iv
{
   struct marshal_cmd_base cmd_base;
   GLint v[4];
};
void
_mesa_unmarshal_RasterPos4iv(struct gl_context *ctx, const struct marshal_cmd_RasterPos4iv *cmd)
{
   const GLint * v = cmd->v;
   CALL_RasterPos4iv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_RasterPos4iv(const GLint * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_RasterPos4iv);
   struct marshal_cmd_RasterPos4iv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_RasterPos4iv, cmd_size);
   memcpy(cmd->v, v, 4 * sizeof(GLint));
}


/* RasterPos4s: marshalled asynchronously */
struct marshal_cmd_RasterPos4s
{
   struct marshal_cmd_base cmd_base;
   GLshort x;
   GLshort y;
   GLshort z;
   GLshort w;
};
void
_mesa_unmarshal_RasterPos4s(struct gl_context *ctx, const struct marshal_cmd_RasterPos4s *cmd)
{
   const GLshort x = cmd->x;
   const GLshort y = cmd->y;
   const GLshort z = cmd->z;
   const GLshort w = cmd->w;
   CALL_RasterPos4s(ctx->CurrentServerDispatch, (x, y, z, w));
}
void GLAPIENTRY
_mesa_marshal_RasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_RasterPos4s);
   struct marshal_cmd_RasterPos4s *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_RasterPos4s, cmd_size);
   cmd->x = x;
   cmd->y = y;
   cmd->z = z;
   cmd->w = w;
}


/* RasterPos4sv: marshalled asynchronously */
struct marshal_cmd_RasterPos4sv
{
   struct marshal_cmd_base cmd_base;
   GLshort v[4];
};
void
_mesa_unmarshal_RasterPos4sv(struct gl_context *ctx, const struct marshal_cmd_RasterPos4sv *cmd)
{
   const GLshort * v = cmd->v;
   CALL_RasterPos4sv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_RasterPos4sv(const GLshort * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_RasterPos4sv);
   struct marshal_cmd_RasterPos4sv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_RasterPos4sv, cmd_size);
   memcpy(cmd->v, v, 4 * sizeof(GLshort));
}


/* Rectd: marshalled asynchronously */
struct marshal_cmd_Rectd
{
   struct marshal_cmd_base cmd_base;
   GLdouble x1;
   GLdouble y1;
   GLdouble x2;
   GLdouble y2;
};
void
_mesa_unmarshal_Rectd(struct gl_context *ctx, const struct marshal_cmd_Rectd *cmd)
{
   const GLdouble x1 = cmd->x1;
   const GLdouble y1 = cmd->y1;
   const GLdouble x2 = cmd->x2;
   const GLdouble y2 = cmd->y2;
   CALL_Rectd(ctx->CurrentServerDispatch, (x1, y1, x2, y2));
}
void GLAPIENTRY
_mesa_marshal_Rectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Rectd);
   struct marshal_cmd_Rectd *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Rectd, cmd_size);
   cmd->x1 = x1;
   cmd->y1 = y1;
   cmd->x2 = x2;
   cmd->y2 = y2;
}


/* Rectdv: marshalled asynchronously */
struct marshal_cmd_Rectdv
{
   struct marshal_cmd_base cmd_base;
   GLdouble v1[2];
   GLdouble v2[2];
};
void
_mesa_unmarshal_Rectdv(struct gl_context *ctx, const struct marshal_cmd_Rectdv *cmd)
{
   const GLdouble * v1 = cmd->v1;
   const GLdouble * v2 = cmd->v2;
   CALL_Rectdv(ctx->CurrentServerDispatch, (v1, v2));
}
void GLAPIENTRY
_mesa_marshal_Rectdv(const GLdouble * v1, const GLdouble * v2)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Rectdv);
   struct marshal_cmd_Rectdv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Rectdv, cmd_size);
   memcpy(cmd->v1, v1, 2 * sizeof(GLdouble));
   memcpy(cmd->v2, v2, 2 * sizeof(GLdouble));
}


/* Rectf: marshalled asynchronously */
struct marshal_cmd_Rectf
{
   struct marshal_cmd_base cmd_base;
   GLfloat x1;
   GLfloat y1;
   GLfloat x2;
   GLfloat y2;
};
void
_mesa_unmarshal_Rectf(struct gl_context *ctx, const struct marshal_cmd_Rectf *cmd)
{
   const GLfloat x1 = cmd->x1;
   const GLfloat y1 = cmd->y1;
   const GLfloat x2 = cmd->x2;
   const GLfloat y2 = cmd->y2;
   CALL_Rectf(ctx->CurrentServerDispatch, (x1, y1, x2, y2));
}
void GLAPIENTRY
_mesa_marshal_Rectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Rectf);
   struct marshal_cmd_Rectf *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Rectf, cmd_size);
   cmd->x1 = x1;
   cmd->y1 = y1;
   cmd->x2 = x2;
   cmd->y2 = y2;
}


/* Rectfv: marshalled asynchronously */
struct marshal_cmd_Rectfv
{
   struct marshal_cmd_base cmd_base;
   GLfloat v1[2];
   GLfloat v2[2];
};
void
_mesa_unmarshal_Rectfv(struct gl_context *ctx, const struct marshal_cmd_Rectfv *cmd)
{
   const GLfloat * v1 = cmd->v1;
   const GLfloat * v2 = cmd->v2;
   CALL_Rectfv(ctx->CurrentServerDispatch, (v1, v2));
}
void GLAPIENTRY
_mesa_marshal_Rectfv(const GLfloat * v1, const GLfloat * v2)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Rectfv);
   struct marshal_cmd_Rectfv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Rectfv, cmd_size);
   memcpy(cmd->v1, v1, 2 * sizeof(GLfloat));
   memcpy(cmd->v2, v2, 2 * sizeof(GLfloat));
}


/* Recti: marshalled asynchronously */
struct marshal_cmd_Recti
{
   struct marshal_cmd_base cmd_base;
   GLint x1;
   GLint y1;
   GLint x2;
   GLint y2;
};
void
_mesa_unmarshal_Recti(struct gl_context *ctx, const struct marshal_cmd_Recti *cmd)
{
   const GLint x1 = cmd->x1;
   const GLint y1 = cmd->y1;
   const GLint x2 = cmd->x2;
   const GLint y2 = cmd->y2;
   CALL_Recti(ctx->CurrentServerDispatch, (x1, y1, x2, y2));
}
void GLAPIENTRY
_mesa_marshal_Recti(GLint x1, GLint y1, GLint x2, GLint y2)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Recti);
   struct marshal_cmd_Recti *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Recti, cmd_size);
   cmd->x1 = x1;
   cmd->y1 = y1;
   cmd->x2 = x2;
   cmd->y2 = y2;
}


/* Rectiv: marshalled asynchronously */
struct marshal_cmd_Rectiv
{
   struct marshal_cmd_base cmd_base;
   GLint v1[2];
   GLint v2[2];
};
void
_mesa_unmarshal_Rectiv(struct gl_context *ctx, const struct marshal_cmd_Rectiv *cmd)
{
   const GLint * v1 = cmd->v1;
   const GLint * v2 = cmd->v2;
   CALL_Rectiv(ctx->CurrentServerDispatch, (v1, v2));
}
void GLAPIENTRY
_mesa_marshal_Rectiv(const GLint * v1, const GLint * v2)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Rectiv);
   struct marshal_cmd_Rectiv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Rectiv, cmd_size);
   memcpy(cmd->v1, v1, 2 * sizeof(GLint));
   memcpy(cmd->v2, v2, 2 * sizeof(GLint));
}


/* Rects: marshalled asynchronously */
struct marshal_cmd_Rects
{
   struct marshal_cmd_base cmd_base;
   GLshort x1;
   GLshort y1;
   GLshort x2;
   GLshort y2;
};
void
_mesa_unmarshal_Rects(struct gl_context *ctx, const struct marshal_cmd_Rects *cmd)
{
   const GLshort x1 = cmd->x1;
   const GLshort y1 = cmd->y1;
   const GLshort x2 = cmd->x2;
   const GLshort y2 = cmd->y2;
   CALL_Rects(ctx->CurrentServerDispatch, (x1, y1, x2, y2));
}
void GLAPIENTRY
_mesa_marshal_Rects(GLshort x1, GLshort y1, GLshort x2, GLshort y2)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Rects);
   struct marshal_cmd_Rects *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Rects, cmd_size);
   cmd->x1 = x1;
   cmd->y1 = y1;
   cmd->x2 = x2;
   cmd->y2 = y2;
}


/* Rectsv: marshalled asynchronously */
struct marshal_cmd_Rectsv
{
   struct marshal_cmd_base cmd_base;
   GLshort v1[2];
   GLshort v2[2];
};
void
_mesa_unmarshal_Rectsv(struct gl_context *ctx, const struct marshal_cmd_Rectsv *cmd)
{
   const GLshort * v1 = cmd->v1;
   const GLshort * v2 = cmd->v2;
   CALL_Rectsv(ctx->CurrentServerDispatch, (v1, v2));
}
void GLAPIENTRY
_mesa_marshal_Rectsv(const GLshort * v1, const GLshort * v2)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Rectsv);
   struct marshal_cmd_Rectsv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Rectsv, cmd_size);
   memcpy(cmd->v1, v1, 2 * sizeof(GLshort));
   memcpy(cmd->v2, v2, 2 * sizeof(GLshort));
}


/* TexCoord1d: marshalled asynchronously */
struct marshal_cmd_TexCoord1d
{
   struct marshal_cmd_base cmd_base;
   GLdouble s;
};
void
_mesa_unmarshal_TexCoord1d(struct gl_context *ctx, const struct marshal_cmd_TexCoord1d *cmd)
{
   const GLdouble s = cmd->s;
   CALL_TexCoord1d(ctx->CurrentServerDispatch, (s));
}
void GLAPIENTRY
_mesa_marshal_TexCoord1d(GLdouble s)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexCoord1d);
   struct marshal_cmd_TexCoord1d *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexCoord1d, cmd_size);
   cmd->s = s;
}


/* TexCoord1dv: marshalled asynchronously */
struct marshal_cmd_TexCoord1dv
{
   struct marshal_cmd_base cmd_base;
   GLdouble v[1];
};
void
_mesa_unmarshal_TexCoord1dv(struct gl_context *ctx, const struct marshal_cmd_TexCoord1dv *cmd)
{
   const GLdouble * v = cmd->v;
   CALL_TexCoord1dv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_TexCoord1dv(const GLdouble * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexCoord1dv);
   struct marshal_cmd_TexCoord1dv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexCoord1dv, cmd_size);
   memcpy(cmd->v, v, 1 * sizeof(GLdouble));
}


/* TexCoord1f: marshalled asynchronously */
struct marshal_cmd_TexCoord1f
{
   struct marshal_cmd_base cmd_base;
   GLfloat s;
};
void
_mesa_unmarshal_TexCoord1f(struct gl_context *ctx, const struct marshal_cmd_TexCoord1f *cmd)
{
   const GLfloat s = cmd->s;
   CALL_TexCoord1f(ctx->CurrentServerDispatch, (s));
}
void GLAPIENTRY
_mesa_marshal_TexCoord1f(GLfloat s)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexCoord1f);
   struct marshal_cmd_TexCoord1f *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexCoord1f, cmd_size);
   cmd->s = s;
}


/* TexCoord1fv: marshalled asynchronously */
struct marshal_cmd_TexCoord1fv
{
   struct marshal_cmd_base cmd_base;
   GLfloat v[1];
};
void
_mesa_unmarshal_TexCoord1fv(struct gl_context *ctx, const struct marshal_cmd_TexCoord1fv *cmd)
{
   const GLfloat * v = cmd->v;
   CALL_TexCoord1fv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_TexCoord1fv(const GLfloat * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexCoord1fv);
   struct marshal_cmd_TexCoord1fv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexCoord1fv, cmd_size);
   memcpy(cmd->v, v, 1 * sizeof(GLfloat));
}


/* TexCoord1i: marshalled asynchronously */
struct marshal_cmd_TexCoord1i
{
   struct marshal_cmd_base cmd_base;
   GLint s;
};
void
_mesa_unmarshal_TexCoord1i(struct gl_context *ctx, const struct marshal_cmd_TexCoord1i *cmd)
{
   const GLint s = cmd->s;
   CALL_TexCoord1i(ctx->CurrentServerDispatch, (s));
}
void GLAPIENTRY
_mesa_marshal_TexCoord1i(GLint s)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexCoord1i);
   struct marshal_cmd_TexCoord1i *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexCoord1i, cmd_size);
   cmd->s = s;
}


/* TexCoord1iv: marshalled asynchronously */
struct marshal_cmd_TexCoord1iv
{
   struct marshal_cmd_base cmd_base;
   GLint v[1];
};
void
_mesa_unmarshal_TexCoord1iv(struct gl_context *ctx, const struct marshal_cmd_TexCoord1iv *cmd)
{
   const GLint * v = cmd->v;
   CALL_TexCoord1iv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_TexCoord1iv(const GLint * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexCoord1iv);
   struct marshal_cmd_TexCoord1iv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexCoord1iv, cmd_size);
   memcpy(cmd->v, v, 1 * sizeof(GLint));
}


/* TexCoord1s: marshalled asynchronously */
struct marshal_cmd_TexCoord1s
{
   struct marshal_cmd_base cmd_base;
   GLshort s;
};
void
_mesa_unmarshal_TexCoord1s(struct gl_context *ctx, const struct marshal_cmd_TexCoord1s *cmd)
{
   const GLshort s = cmd->s;
   CALL_TexCoord1s(ctx->CurrentServerDispatch, (s));
}
void GLAPIENTRY
_mesa_marshal_TexCoord1s(GLshort s)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexCoord1s);
   struct marshal_cmd_TexCoord1s *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexCoord1s, cmd_size);
   cmd->s = s;
}


/* TexCoord1sv: marshalled asynchronously */
struct marshal_cmd_TexCoord1sv
{
   struct marshal_cmd_base cmd_base;
   GLshort v[1];
};
void
_mesa_unmarshal_TexCoord1sv(struct gl_context *ctx, const struct marshal_cmd_TexCoord1sv *cmd)
{
   const GLshort * v = cmd->v;
   CALL_TexCoord1sv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_TexCoord1sv(const GLshort * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexCoord1sv);
   struct marshal_cmd_TexCoord1sv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexCoord1sv, cmd_size);
   memcpy(cmd->v, v, 1 * sizeof(GLshort));
}


/* TexCoord2d: marshalled asynchronously */
struct marshal_cmd_TexCoord2d
{
   struct marshal_cmd_base cmd_base;
   GLdouble s;
   GLdouble t;
};
void
_mesa_unmarshal_TexCoord2d(struct gl_context *ctx, const struct marshal_cmd_TexCoord2d *cmd)
{
   const GLdouble s = cmd->s;
   const GLdouble t = cmd->t;
   CALL_TexCoord2d(ctx->CurrentServerDispatch, (s, t));
}
void GLAPIENTRY
_mesa_marshal_TexCoord2d(GLdouble s, GLdouble t)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexCoord2d);
   struct marshal_cmd_TexCoord2d *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexCoord2d, cmd_size);
   cmd->s = s;
   cmd->t = t;
}


/* TexCoord2dv: marshalled asynchronously */
struct marshal_cmd_TexCoord2dv
{
   struct marshal_cmd_base cmd_base;
   GLdouble v[2];
};
void
_mesa_unmarshal_TexCoord2dv(struct gl_context *ctx, const struct marshal_cmd_TexCoord2dv *cmd)
{
   const GLdouble * v = cmd->v;
   CALL_TexCoord2dv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_TexCoord2dv(const GLdouble * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexCoord2dv);
   struct marshal_cmd_TexCoord2dv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexCoord2dv, cmd_size);
   memcpy(cmd->v, v, 2 * sizeof(GLdouble));
}


/* TexCoord2f: marshalled asynchronously */
struct marshal_cmd_TexCoord2f
{
   struct marshal_cmd_base cmd_base;
   GLfloat s;
   GLfloat t;
};
void
_mesa_unmarshal_TexCoord2f(struct gl_context *ctx, const struct marshal_cmd_TexCoord2f *cmd)
{
   const GLfloat s = cmd->s;
   const GLfloat t = cmd->t;
   CALL_TexCoord2f(ctx->CurrentServerDispatch, (s, t));
}
void GLAPIENTRY
_mesa_marshal_TexCoord2f(GLfloat s, GLfloat t)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexCoord2f);
   struct marshal_cmd_TexCoord2f *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexCoord2f, cmd_size);
   cmd->s = s;
   cmd->t = t;
}


/* TexCoord2fv: marshalled asynchronously */
struct marshal_cmd_TexCoord2fv
{
   struct marshal_cmd_base cmd_base;
   GLfloat v[2];
};
void
_mesa_unmarshal_TexCoord2fv(struct gl_context *ctx, const struct marshal_cmd_TexCoord2fv *cmd)
{
   const GLfloat * v = cmd->v;
   CALL_TexCoord2fv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_TexCoord2fv(const GLfloat * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexCoord2fv);
   struct marshal_cmd_TexCoord2fv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexCoord2fv, cmd_size);
   memcpy(cmd->v, v, 2 * sizeof(GLfloat));
}


/* TexCoord2i: marshalled asynchronously */
struct marshal_cmd_TexCoord2i
{
   struct marshal_cmd_base cmd_base;
   GLint s;
   GLint t;
};
void
_mesa_unmarshal_TexCoord2i(struct gl_context *ctx, const struct marshal_cmd_TexCoord2i *cmd)
{
   const GLint s = cmd->s;
   const GLint t = cmd->t;
   CALL_TexCoord2i(ctx->CurrentServerDispatch, (s, t));
}
void GLAPIENTRY
_mesa_marshal_TexCoord2i(GLint s, GLint t)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexCoord2i);
   struct marshal_cmd_TexCoord2i *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexCoord2i, cmd_size);
   cmd->s = s;
   cmd->t = t;
}


/* TexCoord2iv: marshalled asynchronously */
struct marshal_cmd_TexCoord2iv
{
   struct marshal_cmd_base cmd_base;
   GLint v[2];
};
void
_mesa_unmarshal_TexCoord2iv(struct gl_context *ctx, const struct marshal_cmd_TexCoord2iv *cmd)
{
   const GLint * v = cmd->v;
   CALL_TexCoord2iv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_TexCoord2iv(const GLint * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexCoord2iv);
   struct marshal_cmd_TexCoord2iv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexCoord2iv, cmd_size);
   memcpy(cmd->v, v, 2 * sizeof(GLint));
}


/* TexCoord2s: marshalled asynchronously */
struct marshal_cmd_TexCoord2s
{
   struct marshal_cmd_base cmd_base;
   GLshort s;
   GLshort t;
};
void
_mesa_unmarshal_TexCoord2s(struct gl_context *ctx, const struct marshal_cmd_TexCoord2s *cmd)
{
   const GLshort s = cmd->s;
   const GLshort t = cmd->t;
   CALL_TexCoord2s(ctx->CurrentServerDispatch, (s, t));
}
void GLAPIENTRY
_mesa_marshal_TexCoord2s(GLshort s, GLshort t)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexCoord2s);
   struct marshal_cmd_TexCoord2s *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexCoord2s, cmd_size);
   cmd->s = s;
   cmd->t = t;
}


/* TexCoord2sv: marshalled asynchronously */
struct marshal_cmd_TexCoord2sv
{
   struct marshal_cmd_base cmd_base;
   GLshort v[2];
};
void
_mesa_unmarshal_TexCoord2sv(struct gl_context *ctx, const struct marshal_cmd_TexCoord2sv *cmd)
{
   const GLshort * v = cmd->v;
   CALL_TexCoord2sv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_TexCoord2sv(const GLshort * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexCoord2sv);
   struct marshal_cmd_TexCoord2sv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexCoord2sv, cmd_size);
   memcpy(cmd->v, v, 2 * sizeof(GLshort));
}


/* TexCoord3d: marshalled asynchronously */
struct marshal_cmd_TexCoord3d
{
   struct marshal_cmd_base cmd_base;
   GLdouble s;
   GLdouble t;
   GLdouble r;
};
void
_mesa_unmarshal_TexCoord3d(struct gl_context *ctx, const struct marshal_cmd_TexCoord3d *cmd)
{
   const GLdouble s = cmd->s;
   const GLdouble t = cmd->t;
   const GLdouble r = cmd->r;
   CALL_TexCoord3d(ctx->CurrentServerDispatch, (s, t, r));
}
void GLAPIENTRY
_mesa_marshal_TexCoord3d(GLdouble s, GLdouble t, GLdouble r)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexCoord3d);
   struct marshal_cmd_TexCoord3d *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexCoord3d, cmd_size);
   cmd->s = s;
   cmd->t = t;
   cmd->r = r;
}


/* TexCoord3dv: marshalled asynchronously */
struct marshal_cmd_TexCoord3dv
{
   struct marshal_cmd_base cmd_base;
   GLdouble v[3];
};
void
_mesa_unmarshal_TexCoord3dv(struct gl_context *ctx, const struct marshal_cmd_TexCoord3dv *cmd)
{
   const GLdouble * v = cmd->v;
   CALL_TexCoord3dv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_TexCoord3dv(const GLdouble * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexCoord3dv);
   struct marshal_cmd_TexCoord3dv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexCoord3dv, cmd_size);
   memcpy(cmd->v, v, 3 * sizeof(GLdouble));
}


/* TexCoord3f: marshalled asynchronously */
struct marshal_cmd_TexCoord3f
{
   struct marshal_cmd_base cmd_base;
   GLfloat s;
   GLfloat t;
   GLfloat r;
};
void
_mesa_unmarshal_TexCoord3f(struct gl_context *ctx, const struct marshal_cmd_TexCoord3f *cmd)
{
   const GLfloat s = cmd->s;
   const GLfloat t = cmd->t;
   const GLfloat r = cmd->r;
   CALL_TexCoord3f(ctx->CurrentServerDispatch, (s, t, r));
}
void GLAPIENTRY
_mesa_marshal_TexCoord3f(GLfloat s, GLfloat t, GLfloat r)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexCoord3f);
   struct marshal_cmd_TexCoord3f *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexCoord3f, cmd_size);
   cmd->s = s;
   cmd->t = t;
   cmd->r = r;
}


/* TexCoord3fv: marshalled asynchronously */
struct marshal_cmd_TexCoord3fv
{
   struct marshal_cmd_base cmd_base;
   GLfloat v[3];
};
void
_mesa_unmarshal_TexCoord3fv(struct gl_context *ctx, const struct marshal_cmd_TexCoord3fv *cmd)
{
   const GLfloat * v = cmd->v;
   CALL_TexCoord3fv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_TexCoord3fv(const GLfloat * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexCoord3fv);
   struct marshal_cmd_TexCoord3fv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexCoord3fv, cmd_size);
   memcpy(cmd->v, v, 3 * sizeof(GLfloat));
}


/* TexCoord3i: marshalled asynchronously */
struct marshal_cmd_TexCoord3i
{
   struct marshal_cmd_base cmd_base;
   GLint s;
   GLint t;
   GLint r;
};
void
_mesa_unmarshal_TexCoord3i(struct gl_context *ctx, const struct marshal_cmd_TexCoord3i *cmd)
{
   const GLint s = cmd->s;
   const GLint t = cmd->t;
   const GLint r = cmd->r;
   CALL_TexCoord3i(ctx->CurrentServerDispatch, (s, t, r));
}
void GLAPIENTRY
_mesa_marshal_TexCoord3i(GLint s, GLint t, GLint r)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexCoord3i);
   struct marshal_cmd_TexCoord3i *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexCoord3i, cmd_size);
   cmd->s = s;
   cmd->t = t;
   cmd->r = r;
}


/* TexCoord3iv: marshalled asynchronously */
struct marshal_cmd_TexCoord3iv
{
   struct marshal_cmd_base cmd_base;
   GLint v[3];
};
void
_mesa_unmarshal_TexCoord3iv(struct gl_context *ctx, const struct marshal_cmd_TexCoord3iv *cmd)
{
   const GLint * v = cmd->v;
   CALL_TexCoord3iv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_TexCoord3iv(const GLint * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexCoord3iv);
   struct marshal_cmd_TexCoord3iv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexCoord3iv, cmd_size);
   memcpy(cmd->v, v, 3 * sizeof(GLint));
}


/* TexCoord3s: marshalled asynchronously */
struct marshal_cmd_TexCoord3s
{
   struct marshal_cmd_base cmd_base;
   GLshort s;
   GLshort t;
   GLshort r;
};
void
_mesa_unmarshal_TexCoord3s(struct gl_context *ctx, const struct marshal_cmd_TexCoord3s *cmd)
{
   const GLshort s = cmd->s;
   const GLshort t = cmd->t;
   const GLshort r = cmd->r;
   CALL_TexCoord3s(ctx->CurrentServerDispatch, (s, t, r));
}
void GLAPIENTRY
_mesa_marshal_TexCoord3s(GLshort s, GLshort t, GLshort r)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexCoord3s);
   struct marshal_cmd_TexCoord3s *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexCoord3s, cmd_size);
   cmd->s = s;
   cmd->t = t;
   cmd->r = r;
}


/* TexCoord3sv: marshalled asynchronously */
struct marshal_cmd_TexCoord3sv
{
   struct marshal_cmd_base cmd_base;
   GLshort v[3];
};
void
_mesa_unmarshal_TexCoord3sv(struct gl_context *ctx, const struct marshal_cmd_TexCoord3sv *cmd)
{
   const GLshort * v = cmd->v;
   CALL_TexCoord3sv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_TexCoord3sv(const GLshort * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexCoord3sv);
   struct marshal_cmd_TexCoord3sv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexCoord3sv, cmd_size);
   memcpy(cmd->v, v, 3 * sizeof(GLshort));
}


/* TexCoord4d: marshalled asynchronously */
struct marshal_cmd_TexCoord4d
{
   struct marshal_cmd_base cmd_base;
   GLdouble s;
   GLdouble t;
   GLdouble r;
   GLdouble q;
};
void
_mesa_unmarshal_TexCoord4d(struct gl_context *ctx, const struct marshal_cmd_TexCoord4d *cmd)
{
   const GLdouble s = cmd->s;
   const GLdouble t = cmd->t;
   const GLdouble r = cmd->r;
   const GLdouble q = cmd->q;
   CALL_TexCoord4d(ctx->CurrentServerDispatch, (s, t, r, q));
}
void GLAPIENTRY
_mesa_marshal_TexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexCoord4d);
   struct marshal_cmd_TexCoord4d *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexCoord4d, cmd_size);
   cmd->s = s;
   cmd->t = t;
   cmd->r = r;
   cmd->q = q;
}


/* TexCoord4dv: marshalled asynchronously */
struct marshal_cmd_TexCoord4dv
{
   struct marshal_cmd_base cmd_base;
   GLdouble v[4];
};
void
_mesa_unmarshal_TexCoord4dv(struct gl_context *ctx, const struct marshal_cmd_TexCoord4dv *cmd)
{
   const GLdouble * v = cmd->v;
   CALL_TexCoord4dv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_TexCoord4dv(const GLdouble * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexCoord4dv);
   struct marshal_cmd_TexCoord4dv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexCoord4dv, cmd_size);
   memcpy(cmd->v, v, 4 * sizeof(GLdouble));
}


/* TexCoord4f: marshalled asynchronously */
struct marshal_cmd_TexCoord4f
{
   struct marshal_cmd_base cmd_base;
   GLfloat s;
   GLfloat t;
   GLfloat r;
   GLfloat q;
};
void
_mesa_unmarshal_TexCoord4f(struct gl_context *ctx, const struct marshal_cmd_TexCoord4f *cmd)
{
   const GLfloat s = cmd->s;
   const GLfloat t = cmd->t;
   const GLfloat r = cmd->r;
   const GLfloat q = cmd->q;
   CALL_TexCoord4f(ctx->CurrentServerDispatch, (s, t, r, q));
}
void GLAPIENTRY
_mesa_marshal_TexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexCoord4f);
   struct marshal_cmd_TexCoord4f *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexCoord4f, cmd_size);
   cmd->s = s;
   cmd->t = t;
   cmd->r = r;
   cmd->q = q;
}


/* TexCoord4fv: marshalled asynchronously */
struct marshal_cmd_TexCoord4fv
{
   struct marshal_cmd_base cmd_base;
   GLfloat v[4];
};
void
_mesa_unmarshal_TexCoord4fv(struct gl_context *ctx, const struct marshal_cmd_TexCoord4fv *cmd)
{
   const GLfloat * v = cmd->v;
   CALL_TexCoord4fv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_TexCoord4fv(const GLfloat * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexCoord4fv);
   struct marshal_cmd_TexCoord4fv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexCoord4fv, cmd_size);
   memcpy(cmd->v, v, 4 * sizeof(GLfloat));
}


/* TexCoord4i: marshalled asynchronously */
struct marshal_cmd_TexCoord4i
{
   struct marshal_cmd_base cmd_base;
   GLint s;
   GLint t;
   GLint r;
   GLint q;
};
void
_mesa_unmarshal_TexCoord4i(struct gl_context *ctx, const struct marshal_cmd_TexCoord4i *cmd)
{
   const GLint s = cmd->s;
   const GLint t = cmd->t;
   const GLint r = cmd->r;
   const GLint q = cmd->q;
   CALL_TexCoord4i(ctx->CurrentServerDispatch, (s, t, r, q));
}
void GLAPIENTRY
_mesa_marshal_TexCoord4i(GLint s, GLint t, GLint r, GLint q)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexCoord4i);
   struct marshal_cmd_TexCoord4i *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexCoord4i, cmd_size);
   cmd->s = s;
   cmd->t = t;
   cmd->r = r;
   cmd->q = q;
}


/* TexCoord4iv: marshalled asynchronously */
struct marshal_cmd_TexCoord4iv
{
   struct marshal_cmd_base cmd_base;
   GLint v[4];
};
void
_mesa_unmarshal_TexCoord4iv(struct gl_context *ctx, const struct marshal_cmd_TexCoord4iv *cmd)
{
   const GLint * v = cmd->v;
   CALL_TexCoord4iv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_TexCoord4iv(const GLint * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexCoord4iv);
   struct marshal_cmd_TexCoord4iv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexCoord4iv, cmd_size);
   memcpy(cmd->v, v, 4 * sizeof(GLint));
}


/* TexCoord4s: marshalled asynchronously */
struct marshal_cmd_TexCoord4s
{
   struct marshal_cmd_base cmd_base;
   GLshort s;
   GLshort t;
   GLshort r;
   GLshort q;
};
void
_mesa_unmarshal_TexCoord4s(struct gl_context *ctx, const struct marshal_cmd_TexCoord4s *cmd)
{
   const GLshort s = cmd->s;
   const GLshort t = cmd->t;
   const GLshort r = cmd->r;
   const GLshort q = cmd->q;
   CALL_TexCoord4s(ctx->CurrentServerDispatch, (s, t, r, q));
}
void GLAPIENTRY
_mesa_marshal_TexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexCoord4s);
   struct marshal_cmd_TexCoord4s *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexCoord4s, cmd_size);
   cmd->s = s;
   cmd->t = t;
   cmd->r = r;
   cmd->q = q;
}


/* TexCoord4sv: marshalled asynchronously */
struct marshal_cmd_TexCoord4sv
{
   struct marshal_cmd_base cmd_base;
   GLshort v[4];
};
void
_mesa_unmarshal_TexCoord4sv(struct gl_context *ctx, const struct marshal_cmd_TexCoord4sv *cmd)
{
   const GLshort * v = cmd->v;
   CALL_TexCoord4sv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_TexCoord4sv(const GLshort * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexCoord4sv);
   struct marshal_cmd_TexCoord4sv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexCoord4sv, cmd_size);
   memcpy(cmd->v, v, 4 * sizeof(GLshort));
}


/* Vertex2d: marshalled asynchronously */
struct marshal_cmd_Vertex2d
{
   struct marshal_cmd_base cmd_base;
   GLdouble x;
   GLdouble y;
};
void
_mesa_unmarshal_Vertex2d(struct gl_context *ctx, const struct marshal_cmd_Vertex2d *cmd)
{
   const GLdouble x = cmd->x;
   const GLdouble y = cmd->y;
   CALL_Vertex2d(ctx->CurrentServerDispatch, (x, y));
}
void GLAPIENTRY
_mesa_marshal_Vertex2d(GLdouble x, GLdouble y)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Vertex2d);
   struct marshal_cmd_Vertex2d *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Vertex2d, cmd_size);
   cmd->x = x;
   cmd->y = y;
}


/* Vertex2dv: marshalled asynchronously */
struct marshal_cmd_Vertex2dv
{
   struct marshal_cmd_base cmd_base;
   GLdouble v[2];
};
void
_mesa_unmarshal_Vertex2dv(struct gl_context *ctx, const struct marshal_cmd_Vertex2dv *cmd)
{
   const GLdouble * v = cmd->v;
   CALL_Vertex2dv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Vertex2dv(const GLdouble * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Vertex2dv);
   struct marshal_cmd_Vertex2dv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Vertex2dv, cmd_size);
   memcpy(cmd->v, v, 2 * sizeof(GLdouble));
}


/* Vertex2f: marshalled asynchronously */
struct marshal_cmd_Vertex2f
{
   struct marshal_cmd_base cmd_base;
   GLfloat x;
   GLfloat y;
};
void
_mesa_unmarshal_Vertex2f(struct gl_context *ctx, const struct marshal_cmd_Vertex2f *cmd)
{
   const GLfloat x = cmd->x;
   const GLfloat y = cmd->y;
   CALL_Vertex2f(ctx->CurrentServerDispatch, (x, y));
}
void GLAPIENTRY
_mesa_marshal_Vertex2f(GLfloat x, GLfloat y)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Vertex2f);
   struct marshal_cmd_Vertex2f *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Vertex2f, cmd_size);
   cmd->x = x;
   cmd->y = y;
}


/* Vertex2fv: marshalled asynchronously */
struct marshal_cmd_Vertex2fv
{
   struct marshal_cmd_base cmd_base;
   GLfloat v[2];
};
void
_mesa_unmarshal_Vertex2fv(struct gl_context *ctx, const struct marshal_cmd_Vertex2fv *cmd)
{
   const GLfloat * v = cmd->v;
   CALL_Vertex2fv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Vertex2fv(const GLfloat * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Vertex2fv);
   struct marshal_cmd_Vertex2fv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Vertex2fv, cmd_size);
   memcpy(cmd->v, v, 2 * sizeof(GLfloat));
}


/* Vertex2i: marshalled asynchronously */
struct marshal_cmd_Vertex2i
{
   struct marshal_cmd_base cmd_base;
   GLint x;
   GLint y;
};
void
_mesa_unmarshal_Vertex2i(struct gl_context *ctx, const struct marshal_cmd_Vertex2i *cmd)
{
   const GLint x = cmd->x;
   const GLint y = cmd->y;
   CALL_Vertex2i(ctx->CurrentServerDispatch, (x, y));
}
void GLAPIENTRY
_mesa_marshal_Vertex2i(GLint x, GLint y)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Vertex2i);
   struct marshal_cmd_Vertex2i *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Vertex2i, cmd_size);
   cmd->x = x;
   cmd->y = y;
}


/* Vertex2iv: marshalled asynchronously */
struct marshal_cmd_Vertex2iv
{
   struct marshal_cmd_base cmd_base;
   GLint v[2];
};
void
_mesa_unmarshal_Vertex2iv(struct gl_context *ctx, const struct marshal_cmd_Vertex2iv *cmd)
{
   const GLint * v = cmd->v;
   CALL_Vertex2iv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Vertex2iv(const GLint * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Vertex2iv);
   struct marshal_cmd_Vertex2iv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Vertex2iv, cmd_size);
   memcpy(cmd->v, v, 2 * sizeof(GLint));
}


/* Vertex2s: marshalled asynchronously */
struct marshal_cmd_Vertex2s
{
   struct marshal_cmd_base cmd_base;
   GLshort x;
   GLshort y;
};
void
_mesa_unmarshal_Vertex2s(struct gl_context *ctx, const struct marshal_cmd_Vertex2s *cmd)
{
   const GLshort x = cmd->x;
   const GLshort y = cmd->y;
   CALL_Vertex2s(ctx->CurrentServerDispatch, (x, y));
}
void GLAPIENTRY
_mesa_marshal_Vertex2s(GLshort x, GLshort y)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Vertex2s);
   struct marshal_cmd_Vertex2s *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Vertex2s, cmd_size);
   cmd->x = x;
   cmd->y = y;
}


/* Vertex2sv: marshalled asynchronously */
struct marshal_cmd_Vertex2sv
{
   struct marshal_cmd_base cmd_base;
   GLshort v[2];
};
void
_mesa_unmarshal_Vertex2sv(struct gl_context *ctx, const struct marshal_cmd_Vertex2sv *cmd)
{
   const GLshort * v = cmd->v;
   CALL_Vertex2sv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Vertex2sv(const GLshort * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Vertex2sv);
   struct marshal_cmd_Vertex2sv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Vertex2sv, cmd_size);
   memcpy(cmd->v, v, 2 * sizeof(GLshort));
}


/* Vertex3d: marshalled asynchronously */
struct marshal_cmd_Vertex3d
{
   struct marshal_cmd_base cmd_base;
   GLdouble x;
   GLdouble y;
   GLdouble z;
};
void
_mesa_unmarshal_Vertex3d(struct gl_context *ctx, const struct marshal_cmd_Vertex3d *cmd)
{
   const GLdouble x = cmd->x;
   const GLdouble y = cmd->y;
   const GLdouble z = cmd->z;
   CALL_Vertex3d(ctx->CurrentServerDispatch, (x, y, z));
}
void GLAPIENTRY
_mesa_marshal_Vertex3d(GLdouble x, GLdouble y, GLdouble z)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Vertex3d);
   struct marshal_cmd_Vertex3d *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Vertex3d, cmd_size);
   cmd->x = x;
   cmd->y = y;
   cmd->z = z;
}


/* Vertex3dv: marshalled asynchronously */
struct marshal_cmd_Vertex3dv
{
   struct marshal_cmd_base cmd_base;
   GLdouble v[3];
};
void
_mesa_unmarshal_Vertex3dv(struct gl_context *ctx, const struct marshal_cmd_Vertex3dv *cmd)
{
   const GLdouble * v = cmd->v;
   CALL_Vertex3dv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Vertex3dv(const GLdouble * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Vertex3dv);
   struct marshal_cmd_Vertex3dv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Vertex3dv, cmd_size);
   memcpy(cmd->v, v, 3 * sizeof(GLdouble));
}


/* Vertex3f: marshalled asynchronously */
struct marshal_cmd_Vertex3f
{
   struct marshal_cmd_base cmd_base;
   GLfloat x;
   GLfloat y;
   GLfloat z;
};
void
_mesa_unmarshal_Vertex3f(struct gl_context *ctx, const struct marshal_cmd_Vertex3f *cmd)
{
   const GLfloat x = cmd->x;
   const GLfloat y = cmd->y;
   const GLfloat z = cmd->z;
   CALL_Vertex3f(ctx->CurrentServerDispatch, (x, y, z));
}
void GLAPIENTRY
_mesa_marshal_Vertex3f(GLfloat x, GLfloat y, GLfloat z)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Vertex3f);
   struct marshal_cmd_Vertex3f *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Vertex3f, cmd_size);
   cmd->x = x;
   cmd->y = y;
   cmd->z = z;
}


/* Vertex3fv: marshalled asynchronously */
struct marshal_cmd_Vertex3fv
{
   struct marshal_cmd_base cmd_base;
   GLfloat v[3];
};
void
_mesa_unmarshal_Vertex3fv(struct gl_context *ctx, const struct marshal_cmd_Vertex3fv *cmd)
{
   const GLfloat * v = cmd->v;
   CALL_Vertex3fv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Vertex3fv(const GLfloat * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Vertex3fv);
   struct marshal_cmd_Vertex3fv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Vertex3fv, cmd_size);
   memcpy(cmd->v, v, 3 * sizeof(GLfloat));
}


/* Vertex3i: marshalled asynchronously */
struct marshal_cmd_Vertex3i
{
   struct marshal_cmd_base cmd_base;
   GLint x;
   GLint y;
   GLint z;
};
void
_mesa_unmarshal_Vertex3i(struct gl_context *ctx, const struct marshal_cmd_Vertex3i *cmd)
{
   const GLint x = cmd->x;
   const GLint y = cmd->y;
   const GLint z = cmd->z;
   CALL_Vertex3i(ctx->CurrentServerDispatch, (x, y, z));
}
void GLAPIENTRY
_mesa_marshal_Vertex3i(GLint x, GLint y, GLint z)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Vertex3i);
   struct marshal_cmd_Vertex3i *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Vertex3i, cmd_size);
   cmd->x = x;
   cmd->y = y;
   cmd->z = z;
}


/* Vertex3iv: marshalled asynchronously */
struct marshal_cmd_Vertex3iv
{
   struct marshal_cmd_base cmd_base;
   GLint v[3];
};
void
_mesa_unmarshal_Vertex3iv(struct gl_context *ctx, const struct marshal_cmd_Vertex3iv *cmd)
{
   const GLint * v = cmd->v;
   CALL_Vertex3iv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Vertex3iv(const GLint * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Vertex3iv);
   struct marshal_cmd_Vertex3iv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Vertex3iv, cmd_size);
   memcpy(cmd->v, v, 3 * sizeof(GLint));
}


/* Vertex3s: marshalled asynchronously */
struct marshal_cmd_Vertex3s
{
   struct marshal_cmd_base cmd_base;
   GLshort x;
   GLshort y;
   GLshort z;
};
void
_mesa_unmarshal_Vertex3s(struct gl_context *ctx, const struct marshal_cmd_Vertex3s *cmd)
{
   const GLshort x = cmd->x;
   const GLshort y = cmd->y;
   const GLshort z = cmd->z;
   CALL_Vertex3s(ctx->CurrentServerDispatch, (x, y, z));
}
void GLAPIENTRY
_mesa_marshal_Vertex3s(GLshort x, GLshort y, GLshort z)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Vertex3s);
   struct marshal_cmd_Vertex3s *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Vertex3s, cmd_size);
   cmd->x = x;
   cmd->y = y;
   cmd->z = z;
}


/* Vertex3sv: marshalled asynchronously */
struct marshal_cmd_Vertex3sv
{
   struct marshal_cmd_base cmd_base;
   GLshort v[3];
};
void
_mesa_unmarshal_Vertex3sv(struct gl_context *ctx, const struct marshal_cmd_Vertex3sv *cmd)
{
   const GLshort * v = cmd->v;
   CALL_Vertex3sv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Vertex3sv(const GLshort * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Vertex3sv);
   struct marshal_cmd_Vertex3sv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Vertex3sv, cmd_size);
   memcpy(cmd->v, v, 3 * sizeof(GLshort));
}


/* Vertex4d: marshalled asynchronously */
struct marshal_cmd_Vertex4d
{
   struct marshal_cmd_base cmd_base;
   GLdouble x;
   GLdouble y;
   GLdouble z;
   GLdouble w;
};
void
_mesa_unmarshal_Vertex4d(struct gl_context *ctx, const struct marshal_cmd_Vertex4d *cmd)
{
   const GLdouble x = cmd->x;
   const GLdouble y = cmd->y;
   const GLdouble z = cmd->z;
   const GLdouble w = cmd->w;
   CALL_Vertex4d(ctx->CurrentServerDispatch, (x, y, z, w));
}
void GLAPIENTRY
_mesa_marshal_Vertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Vertex4d);
   struct marshal_cmd_Vertex4d *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Vertex4d, cmd_size);
   cmd->x = x;
   cmd->y = y;
   cmd->z = z;
   cmd->w = w;
}


/* Vertex4dv: marshalled asynchronously */
struct marshal_cmd_Vertex4dv
{
   struct marshal_cmd_base cmd_base;
   GLdouble v[4];
};
void
_mesa_unmarshal_Vertex4dv(struct gl_context *ctx, const struct marshal_cmd_Vertex4dv *cmd)
{
   const GLdouble * v = cmd->v;
   CALL_Vertex4dv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Vertex4dv(const GLdouble * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Vertex4dv);
   struct marshal_cmd_Vertex4dv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Vertex4dv, cmd_size);
   memcpy(cmd->v, v, 4 * sizeof(GLdouble));
}


/* Vertex4f: marshalled asynchronously */
struct marshal_cmd_Vertex4f
{
   struct marshal_cmd_base cmd_base;
   GLfloat x;
   GLfloat y;
   GLfloat z;
   GLfloat w;
};
void
_mesa_unmarshal_Vertex4f(struct gl_context *ctx, const struct marshal_cmd_Vertex4f *cmd)
{
   const GLfloat x = cmd->x;
   const GLfloat y = cmd->y;
   const GLfloat z = cmd->z;
   const GLfloat w = cmd->w;
   CALL_Vertex4f(ctx->CurrentServerDispatch, (x, y, z, w));
}
void GLAPIENTRY
_mesa_marshal_Vertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Vertex4f);
   struct marshal_cmd_Vertex4f *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Vertex4f, cmd_size);
   cmd->x = x;
   cmd->y = y;
   cmd->z = z;
   cmd->w = w;
}


/* Vertex4fv: marshalled asynchronously */
struct marshal_cmd_Vertex4fv
{
   struct marshal_cmd_base cmd_base;
   GLfloat v[4];
};
void
_mesa_unmarshal_Vertex4fv(struct gl_context *ctx, const struct marshal_cmd_Vertex4fv *cmd)
{
   const GLfloat * v = cmd->v;
   CALL_Vertex4fv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Vertex4fv(const GLfloat * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Vertex4fv);
   struct marshal_cmd_Vertex4fv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Vertex4fv, cmd_size);
   memcpy(cmd->v, v, 4 * sizeof(GLfloat));
}


/* Vertex4i: marshalled asynchronously */
struct marshal_cmd_Vertex4i
{
   struct marshal_cmd_base cmd_base;
   GLint x;
   GLint y;
   GLint z;
   GLint w;
};
void
_mesa_unmarshal_Vertex4i(struct gl_context *ctx, const struct marshal_cmd_Vertex4i *cmd)
{
   const GLint x = cmd->x;
   const GLint y = cmd->y;
   const GLint z = cmd->z;
   const GLint w = cmd->w;
   CALL_Vertex4i(ctx->CurrentServerDispatch, (x, y, z, w));
}
void GLAPIENTRY
_mesa_marshal_Vertex4i(GLint x, GLint y, GLint z, GLint w)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Vertex4i);
   struct marshal_cmd_Vertex4i *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Vertex4i, cmd_size);
   cmd->x = x;
   cmd->y = y;
   cmd->z = z;
   cmd->w = w;
}


/* Vertex4iv: marshalled asynchronously */
struct marshal_cmd_Vertex4iv
{
   struct marshal_cmd_base cmd_base;
   GLint v[4];
};
void
_mesa_unmarshal_Vertex4iv(struct gl_context *ctx, const struct marshal_cmd_Vertex4iv *cmd)
{
   const GLint * v = cmd->v;
   CALL_Vertex4iv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Vertex4iv(const GLint * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Vertex4iv);
   struct marshal_cmd_Vertex4iv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Vertex4iv, cmd_size);
   memcpy(cmd->v, v, 4 * sizeof(GLint));
}


/* Vertex4s: marshalled asynchronously */
struct marshal_cmd_Vertex4s
{
   struct marshal_cmd_base cmd_base;
   GLshort x;
   GLshort y;
   GLshort z;
   GLshort w;
};
void
_mesa_unmarshal_Vertex4s(struct gl_context *ctx, const struct marshal_cmd_Vertex4s *cmd)
{
   const GLshort x = cmd->x;
   const GLshort y = cmd->y;
   const GLshort z = cmd->z;
   const GLshort w = cmd->w;
   CALL_Vertex4s(ctx->CurrentServerDispatch, (x, y, z, w));
}
void GLAPIENTRY
_mesa_marshal_Vertex4s(GLshort x, GLshort y, GLshort z, GLshort w)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Vertex4s);
   struct marshal_cmd_Vertex4s *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Vertex4s, cmd_size);
   cmd->x = x;
   cmd->y = y;
   cmd->z = z;
   cmd->w = w;
}


/* Vertex4sv: marshalled asynchronously */
struct marshal_cmd_Vertex4sv
{
   struct marshal_cmd_base cmd_base;
   GLshort v[4];
};
void
_mesa_unmarshal_Vertex4sv(struct gl_context *ctx, const struct marshal_cmd_Vertex4sv *cmd)
{
   const GLshort * v = cmd->v;
   CALL_Vertex4sv(ctx->CurrentServerDispatch, (v));
}
void GLAPIENTRY
_mesa_marshal_Vertex4sv(const GLshort * v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Vertex4sv);
   struct marshal_cmd_Vertex4sv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Vertex4sv, cmd_size);
   memcpy(cmd->v, v, 4 * sizeof(GLshort));
}


/* ClipPlane: marshalled asynchronously */
struct marshal_cmd_ClipPlane
{
   struct marshal_cmd_base cmd_base;
   GLenum plane;
   GLdouble equation[4];
};
void
_mesa_unmarshal_ClipPlane(struct gl_context *ctx, const struct marshal_cmd_ClipPlane *cmd)
{
   const GLenum plane = cmd->plane;
   const GLdouble * equation = cmd->equation;
   CALL_ClipPlane(ctx->CurrentServerDispatch, (plane, equation));
}
void GLAPIENTRY
_mesa_marshal_ClipPlane(GLenum plane, const GLdouble * equation)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_ClipPlane);
   struct marshal_cmd_ClipPlane *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_ClipPlane, cmd_size);
   cmd->plane = plane;
   memcpy(cmd->equation, equation, 4 * sizeof(GLdouble));
}


/* ColorMaterial: marshalled asynchronously */
struct marshal_cmd_ColorMaterial
{
   struct marshal_cmd_base cmd_base;
   GLenum face;
   GLenum mode;
};
void
_mesa_unmarshal_ColorMaterial(struct gl_context *ctx, const struct marshal_cmd_ColorMaterial *cmd)
{
   const GLenum face = cmd->face;
   const GLenum mode = cmd->mode;
   CALL_ColorMaterial(ctx->CurrentServerDispatch, (face, mode));
}
void GLAPIENTRY
_mesa_marshal_ColorMaterial(GLenum face, GLenum mode)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_ColorMaterial);
   struct marshal_cmd_ColorMaterial *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_ColorMaterial, cmd_size);
   cmd->face = face;
   cmd->mode = mode;
}


/* CullFace: marshalled asynchronously */
struct marshal_cmd_CullFace
{
   struct marshal_cmd_base cmd_base;
   GLenum mode;
};
void
_mesa_unmarshal_CullFace(struct gl_context *ctx, const struct marshal_cmd_CullFace *cmd)
{
   const GLenum mode = cmd->mode;
   CALL_CullFace(ctx->CurrentServerDispatch, (mode));
}
void GLAPIENTRY
_mesa_marshal_CullFace(GLenum mode)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_CullFace);
   struct marshal_cmd_CullFace *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_CullFace, cmd_size);
   cmd->mode = mode;
}


/* Fogf: marshalled asynchronously */
struct marshal_cmd_Fogf
{
   struct marshal_cmd_base cmd_base;
   GLenum pname;
   GLfloat param;
};
void
_mesa_unmarshal_Fogf(struct gl_context *ctx, const struct marshal_cmd_Fogf *cmd)
{
   const GLenum pname = cmd->pname;
   const GLfloat param = cmd->param;
   CALL_Fogf(ctx->CurrentServerDispatch, (pname, param));
}
void GLAPIENTRY
_mesa_marshal_Fogf(GLenum pname, GLfloat param)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Fogf);
   struct marshal_cmd_Fogf *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Fogf, cmd_size);
   cmd->pname = pname;
   cmd->param = param;
}


/* Fogfv: marshalled asynchronously */
struct marshal_cmd_Fogfv
{
   struct marshal_cmd_base cmd_base;
   GLenum pname;
   /* Next safe_mul(_mesa_fog_enum_to_count(pname), 1 * sizeof(GLfloat)) bytes are GLfloat params[None] */
};
void
_mesa_unmarshal_Fogfv(struct gl_context *ctx, const struct marshal_cmd_Fogfv *cmd)
{
   const GLenum pname = cmd->pname;
   GLfloat * params;
   const char *variable_data = (const char *) (cmd + 1);
   params = (GLfloat *) variable_data;
   CALL_Fogfv(ctx->CurrentServerDispatch, (pname, params));
}
void GLAPIENTRY
_mesa_marshal_Fogfv(GLenum pname, const GLfloat * params)
{
   GET_CURRENT_CONTEXT(ctx);
   int params_size = safe_mul(_mesa_fog_enum_to_count(pname), 1 * sizeof(GLfloat));
   int cmd_size = sizeof(struct marshal_cmd_Fogfv) + params_size;
   struct marshal_cmd_Fogfv *cmd;
   if (unlikely(params_size < 0 || (params_size > 0 && !params) || (unsigned)cmd_size > MARSHAL_MAX_CMD_SIZE)) {
      _mesa_glthread_finish_before(ctx, "Fogfv");
      CALL_Fogfv(ctx->CurrentServerDispatch, (pname, params));
      return;
   }
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Fogfv, cmd_size);
   cmd->pname = pname;
   char *variable_data = (char *) (cmd + 1);
   memcpy(variable_data, params, params_size);
}


/* Fogi: marshalled asynchronously */
struct marshal_cmd_Fogi
{
   struct marshal_cmd_base cmd_base;
   GLenum pname;
   GLint param;
};
void
_mesa_unmarshal_Fogi(struct gl_context *ctx, const struct marshal_cmd_Fogi *cmd)
{
   const GLenum pname = cmd->pname;
   const GLint param = cmd->param;
   CALL_Fogi(ctx->CurrentServerDispatch, (pname, param));
}
void GLAPIENTRY
_mesa_marshal_Fogi(GLenum pname, GLint param)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Fogi);
   struct marshal_cmd_Fogi *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Fogi, cmd_size);
   cmd->pname = pname;
   cmd->param = param;
}


/* Fogiv: marshalled asynchronously */
struct marshal_cmd_Fogiv
{
   struct marshal_cmd_base cmd_base;
   GLenum pname;
   /* Next safe_mul(_mesa_fog_enum_to_count(pname), 1 * sizeof(GLint)) bytes are GLint params[None] */
};
void
_mesa_unmarshal_Fogiv(struct gl_context *ctx, const struct marshal_cmd_Fogiv *cmd)
{
   const GLenum pname = cmd->pname;
   GLint * params;
   const char *variable_data = (const char *) (cmd + 1);
   params = (GLint *) variable_data;
   CALL_Fogiv(ctx->CurrentServerDispatch, (pname, params));
}
void GLAPIENTRY
_mesa_marshal_Fogiv(GLenum pname, const GLint * params)
{
   GET_CURRENT_CONTEXT(ctx);
   int params_size = safe_mul(_mesa_fog_enum_to_count(pname), 1 * sizeof(GLint));
   int cmd_size = sizeof(struct marshal_cmd_Fogiv) + params_size;
   struct marshal_cmd_Fogiv *cmd;
   if (unlikely(params_size < 0 || (params_size > 0 && !params) || (unsigned)cmd_size > MARSHAL_MAX_CMD_SIZE)) {
      _mesa_glthread_finish_before(ctx, "Fogiv");
      CALL_Fogiv(ctx->CurrentServerDispatch, (pname, params));
      return;
   }
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Fogiv, cmd_size);
   cmd->pname = pname;
   char *variable_data = (char *) (cmd + 1);
   memcpy(variable_data, params, params_size);
}


/* FrontFace: marshalled asynchronously */
struct marshal_cmd_FrontFace
{
   struct marshal_cmd_base cmd_base;
   GLenum mode;
};
void
_mesa_unmarshal_FrontFace(struct gl_context *ctx, const struct marshal_cmd_FrontFace *cmd)
{
   const GLenum mode = cmd->mode;
   CALL_FrontFace(ctx->CurrentServerDispatch, (mode));
}
void GLAPIENTRY
_mesa_marshal_FrontFace(GLenum mode)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_FrontFace);
   struct marshal_cmd_FrontFace *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_FrontFace, cmd_size);
   cmd->mode = mode;
}


/* Hint: marshalled asynchronously */
struct marshal_cmd_Hint
{
   struct marshal_cmd_base cmd_base;
   GLenum target;
   GLenum mode;
};
void
_mesa_unmarshal_Hint(struct gl_context *ctx, const struct marshal_cmd_Hint *cmd)
{
   const GLenum target = cmd->target;
   const GLenum mode = cmd->mode;
   CALL_Hint(ctx->CurrentServerDispatch, (target, mode));
}
void GLAPIENTRY
_mesa_marshal_Hint(GLenum target, GLenum mode)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Hint);
   struct marshal_cmd_Hint *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Hint, cmd_size);
   cmd->target = target;
   cmd->mode = mode;
}


/* Lightf: marshalled asynchronously */
struct marshal_cmd_Lightf
{
   struct marshal_cmd_base cmd_base;
   GLenum light;
   GLenum pname;
   GLfloat param;
};
void
_mesa_unmarshal_Lightf(struct gl_context *ctx, const struct marshal_cmd_Lightf *cmd)
{
   const GLenum light = cmd->light;
   const GLenum pname = cmd->pname;
   const GLfloat param = cmd->param;
   CALL_Lightf(ctx->CurrentServerDispatch, (light, pname, param));
}
void GLAPIENTRY
_mesa_marshal_Lightf(GLenum light, GLenum pname, GLfloat param)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Lightf);
   struct marshal_cmd_Lightf *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Lightf, cmd_size);
   cmd->light = light;
   cmd->pname = pname;
   cmd->param = param;
}


/* Lightfv: marshalled asynchronously */
struct marshal_cmd_Lightfv
{
   struct marshal_cmd_base cmd_base;
   GLenum light;
   GLenum pname;
   /* Next safe_mul(_mesa_light_enum_to_count(pname), 1 * sizeof(GLfloat)) bytes are GLfloat params[None] */
};
void
_mesa_unmarshal_Lightfv(struct gl_context *ctx, const struct marshal_cmd_Lightfv *cmd)
{
   const GLenum light = cmd->light;
   const GLenum pname = cmd->pname;
   GLfloat * params;
   const char *variable_data = (const char *) (cmd + 1);
   params = (GLfloat *) variable_data;
   CALL_Lightfv(ctx->CurrentServerDispatch, (light, pname, params));
}
void GLAPIENTRY
_mesa_marshal_Lightfv(GLenum light, GLenum pname, const GLfloat * params)
{
   GET_CURRENT_CONTEXT(ctx);
   int params_size = safe_mul(_mesa_light_enum_to_count(pname), 1 * sizeof(GLfloat));
   int cmd_size = sizeof(struct marshal_cmd_Lightfv) + params_size;
   struct marshal_cmd_Lightfv *cmd;
   if (unlikely(params_size < 0 || (params_size > 0 && !params) || (unsigned)cmd_size > MARSHAL_MAX_CMD_SIZE)) {
      _mesa_glthread_finish_before(ctx, "Lightfv");
      CALL_Lightfv(ctx->CurrentServerDispatch, (light, pname, params));
      return;
   }
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Lightfv, cmd_size);
   cmd->light = light;
   cmd->pname = pname;
   char *variable_data = (char *) (cmd + 1);
   memcpy(variable_data, params, params_size);
}


/* Lighti: marshalled asynchronously */
struct marshal_cmd_Lighti
{
   struct marshal_cmd_base cmd_base;
   GLenum light;
   GLenum pname;
   GLint param;
};
void
_mesa_unmarshal_Lighti(struct gl_context *ctx, const struct marshal_cmd_Lighti *cmd)
{
   const GLenum light = cmd->light;
   const GLenum pname = cmd->pname;
   const GLint param = cmd->param;
   CALL_Lighti(ctx->CurrentServerDispatch, (light, pname, param));
}
void GLAPIENTRY
_mesa_marshal_Lighti(GLenum light, GLenum pname, GLint param)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Lighti);
   struct marshal_cmd_Lighti *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Lighti, cmd_size);
   cmd->light = light;
   cmd->pname = pname;
   cmd->param = param;
}


/* Lightiv: marshalled asynchronously */
struct marshal_cmd_Lightiv
{
   struct marshal_cmd_base cmd_base;
   GLenum light;
   GLenum pname;
   /* Next safe_mul(_mesa_light_enum_to_count(pname), 1 * sizeof(GLint)) bytes are GLint params[None] */
};
void
_mesa_unmarshal_Lightiv(struct gl_context *ctx, const struct marshal_cmd_Lightiv *cmd)
{
   const GLenum light = cmd->light;
   const GLenum pname = cmd->pname;
   GLint * params;
   const char *variable_data = (const char *) (cmd + 1);
   params = (GLint *) variable_data;
   CALL_Lightiv(ctx->CurrentServerDispatch, (light, pname, params));
}
void GLAPIENTRY
_mesa_marshal_Lightiv(GLenum light, GLenum pname, const GLint * params)
{
   GET_CURRENT_CONTEXT(ctx);
   int params_size = safe_mul(_mesa_light_enum_to_count(pname), 1 * sizeof(GLint));
   int cmd_size = sizeof(struct marshal_cmd_Lightiv) + params_size;
   struct marshal_cmd_Lightiv *cmd;
   if (unlikely(params_size < 0 || (params_size > 0 && !params) || (unsigned)cmd_size > MARSHAL_MAX_CMD_SIZE)) {
      _mesa_glthread_finish_before(ctx, "Lightiv");
      CALL_Lightiv(ctx->CurrentServerDispatch, (light, pname, params));
      return;
   }
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Lightiv, cmd_size);
   cmd->light = light;
   cmd->pname = pname;
   char *variable_data = (char *) (cmd + 1);
   memcpy(variable_data, params, params_size);
}


/* LightModelf: marshalled asynchronously */
struct marshal_cmd_LightModelf
{
   struct marshal_cmd_base cmd_base;
   GLenum pname;
   GLfloat param;
};
void
_mesa_unmarshal_LightModelf(struct gl_context *ctx, const struct marshal_cmd_LightModelf *cmd)
{
   const GLenum pname = cmd->pname;
   const GLfloat param = cmd->param;
   CALL_LightModelf(ctx->CurrentServerDispatch, (pname, param));
}
void GLAPIENTRY
_mesa_marshal_LightModelf(GLenum pname, GLfloat param)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_LightModelf);
   struct marshal_cmd_LightModelf *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_LightModelf, cmd_size);
   cmd->pname = pname;
   cmd->param = param;
}


/* LightModelfv: marshalled asynchronously */
struct marshal_cmd_LightModelfv
{
   struct marshal_cmd_base cmd_base;
   GLenum pname;
   /* Next safe_mul(_mesa_light_model_enum_to_count(pname), 1 * sizeof(GLfloat)) bytes are GLfloat params[None] */
};
void
_mesa_unmarshal_LightModelfv(struct gl_context *ctx, const struct marshal_cmd_LightModelfv *cmd)
{
   const GLenum pname = cmd->pname;
   GLfloat * params;
   const char *variable_data = (const char *) (cmd + 1);
   params = (GLfloat *) variable_data;
   CALL_LightModelfv(ctx->CurrentServerDispatch, (pname, params));
}
void GLAPIENTRY
_mesa_marshal_LightModelfv(GLenum pname, const GLfloat * params)
{
   GET_CURRENT_CONTEXT(ctx);
   int params_size = safe_mul(_mesa_light_model_enum_to_count(pname), 1 * sizeof(GLfloat));
   int cmd_size = sizeof(struct marshal_cmd_LightModelfv) + params_size;
   struct marshal_cmd_LightModelfv *cmd;
   if (unlikely(params_size < 0 || (params_size > 0 && !params) || (unsigned)cmd_size > MARSHAL_MAX_CMD_SIZE)) {
      _mesa_glthread_finish_before(ctx, "LightModelfv");
      CALL_LightModelfv(ctx->CurrentServerDispatch, (pname, params));
      return;
   }
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_LightModelfv, cmd_size);
   cmd->pname = pname;
   char *variable_data = (char *) (cmd + 1);
   memcpy(variable_data, params, params_size);
}


/* LightModeli: marshalled asynchronously */
struct marshal_cmd_LightModeli
{
   struct marshal_cmd_base cmd_base;
   GLenum pname;
   GLint param;
};
void
_mesa_unmarshal_LightModeli(struct gl_context *ctx, const struct marshal_cmd_LightModeli *cmd)
{
   const GLenum pname = cmd->pname;
   const GLint param = cmd->param;
   CALL_LightModeli(ctx->CurrentServerDispatch, (pname, param));
}
void GLAPIENTRY
_mesa_marshal_LightModeli(GLenum pname, GLint param)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_LightModeli);
   struct marshal_cmd_LightModeli *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_LightModeli, cmd_size);
   cmd->pname = pname;
   cmd->param = param;
}


/* LightModeliv: marshalled asynchronously */
struct marshal_cmd_LightModeliv
{
   struct marshal_cmd_base cmd_base;
   GLenum pname;
   /* Next safe_mul(_mesa_light_model_enum_to_count(pname), 1 * sizeof(GLint)) bytes are GLint params[None] */
};
void
_mesa_unmarshal_LightModeliv(struct gl_context *ctx, const struct marshal_cmd_LightModeliv *cmd)
{
   const GLenum pname = cmd->pname;
   GLint * params;
   const char *variable_data = (const char *) (cmd + 1);
   params = (GLint *) variable_data;
   CALL_LightModeliv(ctx->CurrentServerDispatch, (pname, params));
}
void GLAPIENTRY
_mesa_marshal_LightModeliv(GLenum pname, const GLint * params)
{
   GET_CURRENT_CONTEXT(ctx);
   int params_size = safe_mul(_mesa_light_model_enum_to_count(pname), 1 * sizeof(GLint));
   int cmd_size = sizeof(struct marshal_cmd_LightModeliv) + params_size;
   struct marshal_cmd_LightModeliv *cmd;
   if (unlikely(params_size < 0 || (params_size > 0 && !params) || (unsigned)cmd_size > MARSHAL_MAX_CMD_SIZE)) {
      _mesa_glthread_finish_before(ctx, "LightModeliv");
      CALL_LightModeliv(ctx->CurrentServerDispatch, (pname, params));
      return;
   }
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_LightModeliv, cmd_size);
   cmd->pname = pname;
   char *variable_data = (char *) (cmd + 1);
   memcpy(variable_data, params, params_size);
}


/* LineStipple: marshalled asynchronously */
struct marshal_cmd_LineStipple
{
   struct marshal_cmd_base cmd_base;
   GLushort pattern;
   GLint factor;
};
void
_mesa_unmarshal_LineStipple(struct gl_context *ctx, const struct marshal_cmd_LineStipple *cmd)
{
   const GLint factor = cmd->factor;
   const GLushort pattern = cmd->pattern;
   CALL_LineStipple(ctx->CurrentServerDispatch, (factor, pattern));
}
void GLAPIENTRY
_mesa_marshal_LineStipple(GLint factor, GLushort pattern)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_LineStipple);
   struct marshal_cmd_LineStipple *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_LineStipple, cmd_size);
   cmd->factor = factor;
   cmd->pattern = pattern;
}


/* LineWidth: marshalled asynchronously */
struct marshal_cmd_LineWidth
{
   struct marshal_cmd_base cmd_base;
   GLfloat width;
};
void
_mesa_unmarshal_LineWidth(struct gl_context *ctx, const struct marshal_cmd_LineWidth *cmd)
{
   const GLfloat width = cmd->width;
   CALL_LineWidth(ctx->CurrentServerDispatch, (width));
}
void GLAPIENTRY
_mesa_marshal_LineWidth(GLfloat width)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_LineWidth);
   struct marshal_cmd_LineWidth *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_LineWidth, cmd_size);
   cmd->width = width;
}


/* Materialf: marshalled asynchronously */
struct marshal_cmd_Materialf
{
   struct marshal_cmd_base cmd_base;
   GLenum face;
   GLenum pname;
   GLfloat param;
};
void
_mesa_unmarshal_Materialf(struct gl_context *ctx, const struct marshal_cmd_Materialf *cmd)
{
   const GLenum face = cmd->face;
   const GLenum pname = cmd->pname;
   const GLfloat param = cmd->param;
   CALL_Materialf(ctx->CurrentServerDispatch, (face, pname, param));
}
void GLAPIENTRY
_mesa_marshal_Materialf(GLenum face, GLenum pname, GLfloat param)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Materialf);
   struct marshal_cmd_Materialf *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Materialf, cmd_size);
   cmd->face = face;
   cmd->pname = pname;
   cmd->param = param;
}


/* Materialfv: marshalled asynchronously */
struct marshal_cmd_Materialfv
{
   struct marshal_cmd_base cmd_base;
   GLenum face;
   GLenum pname;
   /* Next safe_mul(_mesa_material_enum_to_count(pname), 1 * sizeof(GLfloat)) bytes are GLfloat params[None] */
};
void
_mesa_unmarshal_Materialfv(struct gl_context *ctx, const struct marshal_cmd_Materialfv *cmd)
{
   const GLenum face = cmd->face;
   const GLenum pname = cmd->pname;
   GLfloat * params;
   const char *variable_data = (const char *) (cmd + 1);
   params = (GLfloat *) variable_data;
   CALL_Materialfv(ctx->CurrentServerDispatch, (face, pname, params));
}
void GLAPIENTRY
_mesa_marshal_Materialfv(GLenum face, GLenum pname, const GLfloat * params)
{
   GET_CURRENT_CONTEXT(ctx);
   int params_size = safe_mul(_mesa_material_enum_to_count(pname), 1 * sizeof(GLfloat));
   int cmd_size = sizeof(struct marshal_cmd_Materialfv) + params_size;
   struct marshal_cmd_Materialfv *cmd;
   if (unlikely(params_size < 0 || (params_size > 0 && !params) || (unsigned)cmd_size > MARSHAL_MAX_CMD_SIZE)) {
      _mesa_glthread_finish_before(ctx, "Materialfv");
      CALL_Materialfv(ctx->CurrentServerDispatch, (face, pname, params));
      return;
   }
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Materialfv, cmd_size);
   cmd->face = face;
   cmd->pname = pname;
   char *variable_data = (char *) (cmd + 1);
   memcpy(variable_data, params, params_size);
}


/* Materiali: marshalled asynchronously */
struct marshal_cmd_Materiali
{
   struct marshal_cmd_base cmd_base;
   GLenum face;
   GLenum pname;
   GLint param;
};
void
_mesa_unmarshal_Materiali(struct gl_context *ctx, const struct marshal_cmd_Materiali *cmd)
{
   const GLenum face = cmd->face;
   const GLenum pname = cmd->pname;
   const GLint param = cmd->param;
   CALL_Materiali(ctx->CurrentServerDispatch, (face, pname, param));
}
void GLAPIENTRY
_mesa_marshal_Materiali(GLenum face, GLenum pname, GLint param)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Materiali);
   struct marshal_cmd_Materiali *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Materiali, cmd_size);
   cmd->face = face;
   cmd->pname = pname;
   cmd->param = param;
}


/* Materialiv: marshalled asynchronously */
struct marshal_cmd_Materialiv
{
   struct marshal_cmd_base cmd_base;
   GLenum face;
   GLenum pname;
   /* Next safe_mul(_mesa_material_enum_to_count(pname), 1 * sizeof(GLint)) bytes are GLint params[None] */
};
void
_mesa_unmarshal_Materialiv(struct gl_context *ctx, const struct marshal_cmd_Materialiv *cmd)
{
   const GLenum face = cmd->face;
   const GLenum pname = cmd->pname;
   GLint * params;
   const char *variable_data = (const char *) (cmd + 1);
   params = (GLint *) variable_data;
   CALL_Materialiv(ctx->CurrentServerDispatch, (face, pname, params));
}
void GLAPIENTRY
_mesa_marshal_Materialiv(GLenum face, GLenum pname, const GLint * params)
{
   GET_CURRENT_CONTEXT(ctx);
   int params_size = safe_mul(_mesa_material_enum_to_count(pname), 1 * sizeof(GLint));
   int cmd_size = sizeof(struct marshal_cmd_Materialiv) + params_size;
   struct marshal_cmd_Materialiv *cmd;
   if (unlikely(params_size < 0 || (params_size > 0 && !params) || (unsigned)cmd_size > MARSHAL_MAX_CMD_SIZE)) {
      _mesa_glthread_finish_before(ctx, "Materialiv");
      CALL_Materialiv(ctx->CurrentServerDispatch, (face, pname, params));
      return;
   }
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Materialiv, cmd_size);
   cmd->face = face;
   cmd->pname = pname;
   char *variable_data = (char *) (cmd + 1);
   memcpy(variable_data, params, params_size);
}


/* PointSize: marshalled asynchronously */
struct marshal_cmd_PointSize
{
   struct marshal_cmd_base cmd_base;
   GLfloat size;
};
void
_mesa_unmarshal_PointSize(struct gl_context *ctx, const struct marshal_cmd_PointSize *cmd)
{
   const GLfloat size = cmd->size;
   CALL_PointSize(ctx->CurrentServerDispatch, (size));
}
void GLAPIENTRY
_mesa_marshal_PointSize(GLfloat size)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_PointSize);
   struct marshal_cmd_PointSize *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_PointSize, cmd_size);
   cmd->size = size;
}


/* PolygonMode: marshalled asynchronously */
struct marshal_cmd_PolygonMode
{
   struct marshal_cmd_base cmd_base;
   GLenum face;
   GLenum mode;
};
void
_mesa_unmarshal_PolygonMode(struct gl_context *ctx, const struct marshal_cmd_PolygonMode *cmd)
{
   const GLenum face = cmd->face;
   const GLenum mode = cmd->mode;
   CALL_PolygonMode(ctx->CurrentServerDispatch, (face, mode));
}
void GLAPIENTRY
_mesa_marshal_PolygonMode(GLenum face, GLenum mode)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_PolygonMode);
   struct marshal_cmd_PolygonMode *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_PolygonMode, cmd_size);
   cmd->face = face;
   cmd->mode = mode;
}


/* PolygonStipple: marshalled synchronously */
void GLAPIENTRY
_mesa_marshal_PolygonStipple(const GLubyte * mask)
{
   GET_CURRENT_CONTEXT(ctx);
   _mesa_glthread_finish_before(ctx, "PolygonStipple");
   CALL_PolygonStipple(ctx->CurrentServerDispatch, (mask));
}


/* Scissor: marshalled asynchronously */
struct marshal_cmd_Scissor
{
   struct marshal_cmd_base cmd_base;
   GLint x;
   GLint y;
   GLsizei width;
   GLsizei height;
};
void
_mesa_unmarshal_Scissor(struct gl_context *ctx, const struct marshal_cmd_Scissor *cmd)
{
   const GLint x = cmd->x;
   const GLint y = cmd->y;
   const GLsizei width = cmd->width;
   const GLsizei height = cmd->height;
   CALL_Scissor(ctx->CurrentServerDispatch, (x, y, width, height));
}
void GLAPIENTRY
_mesa_marshal_Scissor(GLint x, GLint y, GLsizei width, GLsizei height)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Scissor);
   struct marshal_cmd_Scissor *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Scissor, cmd_size);
   cmd->x = x;
   cmd->y = y;
   cmd->width = width;
   cmd->height = height;
}


/* ShadeModel: marshalled asynchronously */
struct marshal_cmd_ShadeModel
{
   struct marshal_cmd_base cmd_base;
   GLenum mode;
};
void
_mesa_unmarshal_ShadeModel(struct gl_context *ctx, const struct marshal_cmd_ShadeModel *cmd)
{
   const GLenum mode = cmd->mode;
   CALL_ShadeModel(ctx->CurrentServerDispatch, (mode));
}
void GLAPIENTRY
_mesa_marshal_ShadeModel(GLenum mode)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_ShadeModel);
   struct marshal_cmd_ShadeModel *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_ShadeModel, cmd_size);
   cmd->mode = mode;
}


/* TexParameterf: marshalled asynchronously */
struct marshal_cmd_TexParameterf
{
   struct marshal_cmd_base cmd_base;
   GLenum target;
   GLenum pname;
   GLfloat param;
};
void
_mesa_unmarshal_TexParameterf(struct gl_context *ctx, const struct marshal_cmd_TexParameterf *cmd)
{
   const GLenum target = cmd->target;
   const GLenum pname = cmd->pname;
   const GLfloat param = cmd->param;
   CALL_TexParameterf(ctx->CurrentServerDispatch, (target, pname, param));
}
void GLAPIENTRY
_mesa_marshal_TexParameterf(GLenum target, GLenum pname, GLfloat param)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexParameterf);
   struct marshal_cmd_TexParameterf *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexParameterf, cmd_size);
   cmd->target = target;
   cmd->pname = pname;
   cmd->param = param;
}


/* TexParameterfv: marshalled asynchronously */
struct marshal_cmd_TexParameterfv
{
   struct marshal_cmd_base cmd_base;
   GLenum target;
   GLenum pname;
   /* Next safe_mul(_mesa_tex_param_enum_to_count(pname), 1 * sizeof(GLfloat)) bytes are GLfloat params[None] */
};
void
_mesa_unmarshal_TexParameterfv(struct gl_context *ctx, const struct marshal_cmd_TexParameterfv *cmd)
{
   const GLenum target = cmd->target;
   const GLenum pname = cmd->pname;
   GLfloat * params;
   const char *variable_data = (const char *) (cmd + 1);
   params = (GLfloat *) variable_data;
   CALL_TexParameterfv(ctx->CurrentServerDispatch, (target, pname, params));
}
void GLAPIENTRY
_mesa_marshal_TexParameterfv(GLenum target, GLenum pname, const GLfloat * params)
{
   GET_CURRENT_CONTEXT(ctx);
   int params_size = safe_mul(_mesa_tex_param_enum_to_count(pname), 1 * sizeof(GLfloat));
   int cmd_size = sizeof(struct marshal_cmd_TexParameterfv) + params_size;
   struct marshal_cmd_TexParameterfv *cmd;
   if (unlikely(params_size < 0 || (params_size > 0 && !params) || (unsigned)cmd_size > MARSHAL_MAX_CMD_SIZE)) {
      _mesa_glthread_finish_before(ctx, "TexParameterfv");
      CALL_TexParameterfv(ctx->CurrentServerDispatch, (target, pname, params));
      return;
   }
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexParameterfv, cmd_size);
   cmd->target = target;
   cmd->pname = pname;
   char *variable_data = (char *) (cmd + 1);
   memcpy(variable_data, params, params_size);
}


/* TexParameteri: marshalled asynchronously */
struct marshal_cmd_TexParameteri
{
   struct marshal_cmd_base cmd_base;
   GLenum target;
   GLenum pname;
   GLint param;
};
void
_mesa_unmarshal_TexParameteri(struct gl_context *ctx, const struct marshal_cmd_TexParameteri *cmd)
{
   const GLenum target = cmd->target;
   const GLenum pname = cmd->pname;
   const GLint param = cmd->param;
   CALL_TexParameteri(ctx->CurrentServerDispatch, (target, pname, param));
}
void GLAPIENTRY
_mesa_marshal_TexParameteri(GLenum target, GLenum pname, GLint param)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexParameteri);
   struct marshal_cmd_TexParameteri *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexParameteri, cmd_size);
   cmd->target = target;
   cmd->pname = pname;
   cmd->param = param;
}


/* TexParameteriv: marshalled asynchronously */
struct marshal_cmd_TexParameteriv
{
   struct marshal_cmd_base cmd_base;
   GLenum target;
   GLenum pname;
   /* Next safe_mul(_mesa_tex_param_enum_to_count(pname), 1 * sizeof(GLint)) bytes are GLint params[None] */
};
void
_mesa_unmarshal_TexParameteriv(struct gl_context *ctx, const struct marshal_cmd_TexParameteriv *cmd)
{
   const GLenum target = cmd->target;
   const GLenum pname = cmd->pname;
   GLint * params;
   const char *variable_data = (const char *) (cmd + 1);
   params = (GLint *) variable_data;
   CALL_TexParameteriv(ctx->CurrentServerDispatch, (target, pname, params));
}
void GLAPIENTRY
_mesa_marshal_TexParameteriv(GLenum target, GLenum pname, const GLint * params)
{
   GET_CURRENT_CONTEXT(ctx);
   int params_size = safe_mul(_mesa_tex_param_enum_to_count(pname), 1 * sizeof(GLint));
   int cmd_size = sizeof(struct marshal_cmd_TexParameteriv) + params_size;
   struct marshal_cmd_TexParameteriv *cmd;
   if (unlikely(params_size < 0 || (params_size > 0 && !params) || (unsigned)cmd_size > MARSHAL_MAX_CMD_SIZE)) {
      _mesa_glthread_finish_before(ctx, "TexParameteriv");
      CALL_TexParameteriv(ctx->CurrentServerDispatch, (target, pname, params));
      return;
   }
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexParameteriv, cmd_size);
   cmd->target = target;
   cmd->pname = pname;
   char *variable_data = (char *) (cmd + 1);
   memcpy(variable_data, params, params_size);
}


/* TexImage1D: marshalled synchronously */
void GLAPIENTRY
_mesa_marshal_TexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid * pixels)
{
   GET_CURRENT_CONTEXT(ctx);
   _mesa_glthread_finish_before(ctx, "TexImage1D");
   CALL_TexImage1D(ctx->CurrentServerDispatch, (target, level, internalformat, width, border, format, type, pixels));
}


/* TexImage2D: marshalled synchronously */
void GLAPIENTRY
_mesa_marshal_TexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * pixels)
{
   GET_CURRENT_CONTEXT(ctx);
   _mesa_glthread_finish_before(ctx, "TexImage2D");
   CALL_TexImage2D(ctx->CurrentServerDispatch, (target, level, internalformat, width, height, border, format, type, pixels));
}


/* TexEnvf: marshalled asynchronously */
struct marshal_cmd_TexEnvf
{
   struct marshal_cmd_base cmd_base;
   GLenum target;
   GLenum pname;
   GLfloat param;
};
void
_mesa_unmarshal_TexEnvf(struct gl_context *ctx, const struct marshal_cmd_TexEnvf *cmd)
{
   const GLenum target = cmd->target;
   const GLenum pname = cmd->pname;
   const GLfloat param = cmd->param;
   CALL_TexEnvf(ctx->CurrentServerDispatch, (target, pname, param));
}
void GLAPIENTRY
_mesa_marshal_TexEnvf(GLenum target, GLenum pname, GLfloat param)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexEnvf);
   struct marshal_cmd_TexEnvf *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexEnvf, cmd_size);
   cmd->target = target;
   cmd->pname = pname;
   cmd->param = param;
}


/* TexEnvfv: marshalled asynchronously */
struct marshal_cmd_TexEnvfv
{
   struct marshal_cmd_base cmd_base;
   GLenum target;
   GLenum pname;
   /* Next safe_mul(_mesa_texenv_enum_to_count(pname), 1 * sizeof(GLfloat)) bytes are GLfloat params[None] */
};
void
_mesa_unmarshal_TexEnvfv(struct gl_context *ctx, const struct marshal_cmd_TexEnvfv *cmd)
{
   const GLenum target = cmd->target;
   const GLenum pname = cmd->pname;
   GLfloat * params;
   const char *variable_data = (const char *) (cmd + 1);
   params = (GLfloat *) variable_data;
   CALL_TexEnvfv(ctx->CurrentServerDispatch, (target, pname, params));
}
void GLAPIENTRY
_mesa_marshal_TexEnvfv(GLenum target, GLenum pname, const GLfloat * params)
{
   GET_CURRENT_CONTEXT(ctx);
   int params_size = safe_mul(_mesa_texenv_enum_to_count(pname), 1 * sizeof(GLfloat));
   int cmd_size = sizeof(struct marshal_cmd_TexEnvfv) + params_size;
   struct marshal_cmd_TexEnvfv *cmd;
   if (unlikely(params_size < 0 || (params_size > 0 && !params) || (unsigned)cmd_size > MARSHAL_MAX_CMD_SIZE)) {
      _mesa_glthread_finish_before(ctx, "TexEnvfv");
      CALL_TexEnvfv(ctx->CurrentServerDispatch, (target, pname, params));
      return;
   }
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexEnvfv, cmd_size);
   cmd->target = target;
   cmd->pname = pname;
   char *variable_data = (char *) (cmd + 1);
   memcpy(variable_data, params, params_size);
}


/* TexEnvi: marshalled asynchronously */
struct marshal_cmd_TexEnvi
{
   struct marshal_cmd_base cmd_base;
   GLenum target;
   GLenum pname;
   GLint param;
};
void
_mesa_unmarshal_TexEnvi(struct gl_context *ctx, const struct marshal_cmd_TexEnvi *cmd)
{
   const GLenum target = cmd->target;
   const GLenum pname = cmd->pname;
   const GLint param = cmd->param;
   CALL_TexEnvi(ctx->CurrentServerDispatch, (target, pname, param));
}
void GLAPIENTRY
_mesa_marshal_TexEnvi(GLenum target, GLenum pname, GLint param)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexEnvi);
   struct marshal_cmd_TexEnvi *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexEnvi, cmd_size);
   cmd->target = target;
   cmd->pname = pname;
   cmd->param = param;
}


/* TexEnviv: marshalled asynchronously */
struct marshal_cmd_TexEnviv
{
   struct marshal_cmd_base cmd_base;
   GLenum target;
   GLenum pname;
   /* Next safe_mul(_mesa_texenv_enum_to_count(pname), 1 * sizeof(GLint)) bytes are GLint params[None] */
};
void
_mesa_unmarshal_TexEnviv(struct gl_context *ctx, const struct marshal_cmd_TexEnviv *cmd)
{
   const GLenum target = cmd->target;
   const GLenum pname = cmd->pname;
   GLint * params;
   const char *variable_data = (const char *) (cmd + 1);
   params = (GLint *) variable_data;
   CALL_TexEnviv(ctx->CurrentServerDispatch, (target, pname, params));
}
void GLAPIENTRY
_mesa_marshal_TexEnviv(GLenum target, GLenum pname, const GLint * params)
{
   GET_CURRENT_CONTEXT(ctx);
   int params_size = safe_mul(_mesa_texenv_enum_to_count(pname), 1 * sizeof(GLint));
   int cmd_size = sizeof(struct marshal_cmd_TexEnviv) + params_size;
   struct marshal_cmd_TexEnviv *cmd;
   if (unlikely(params_size < 0 || (params_size > 0 && !params) || (unsigned)cmd_size > MARSHAL_MAX_CMD_SIZE)) {
      _mesa_glthread_finish_before(ctx, "TexEnviv");
      CALL_TexEnviv(ctx->CurrentServerDispatch, (target, pname, params));
      return;
   }
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexEnviv, cmd_size);
   cmd->target = target;
   cmd->pname = pname;
   char *variable_data = (char *) (cmd + 1);
   memcpy(variable_data, params, params_size);
}


/* TexGend: marshalled asynchronously */
struct marshal_cmd_TexGend
{
   struct marshal_cmd_base cmd_base;
   GLenum coord;
   GLenum pname;
   GLdouble param;
};
void
_mesa_unmarshal_TexGend(struct gl_context *ctx, const struct marshal_cmd_TexGend *cmd)
{
   const GLenum coord = cmd->coord;
   const GLenum pname = cmd->pname;
   const GLdouble param = cmd->param;
   CALL_TexGend(ctx->CurrentServerDispatch, (coord, pname, param));
}
void GLAPIENTRY
_mesa_marshal_TexGend(GLenum coord, GLenum pname, GLdouble param)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexGend);
   struct marshal_cmd_TexGend *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexGend, cmd_size);
   cmd->coord = coord;
   cmd->pname = pname;
   cmd->param = param;
}


/* TexGendv: marshalled asynchronously */
struct marshal_cmd_TexGendv
{
   struct marshal_cmd_base cmd_base;
   GLenum coord;
   GLenum pname;
   /* Next safe_mul(_mesa_texgen_enum_to_count(pname), 1 * sizeof(GLdouble)) bytes are GLdouble params[None] */
};
void
_mesa_unmarshal_TexGendv(struct gl_context *ctx, const struct marshal_cmd_TexGendv *cmd)
{
   const GLenum coord = cmd->coord;
   const GLenum pname = cmd->pname;
   GLdouble * params;
   const char *variable_data = (const char *) (cmd + 1);
   params = (GLdouble *) variable_data;
   CALL_TexGendv(ctx->CurrentServerDispatch, (coord, pname, params));
}
void GLAPIENTRY
_mesa_marshal_TexGendv(GLenum coord, GLenum pname, const GLdouble * params)
{
   GET_CURRENT_CONTEXT(ctx);
   int params_size = safe_mul(_mesa_texgen_enum_to_count(pname), 1 * sizeof(GLdouble));
   int cmd_size = sizeof(struct marshal_cmd_TexGendv) + params_size;
   struct marshal_cmd_TexGendv *cmd;
   if (unlikely(params_size < 0 || (params_size > 0 && !params) || (unsigned)cmd_size > MARSHAL_MAX_CMD_SIZE)) {
      _mesa_glthread_finish_before(ctx, "TexGendv");
      CALL_TexGendv(ctx->CurrentServerDispatch, (coord, pname, params));
      return;
   }
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexGendv, cmd_size);
   cmd->coord = coord;
   cmd->pname = pname;
   char *variable_data = (char *) (cmd + 1);
   memcpy(variable_data, params, params_size);
}


/* TexGenf: marshalled asynchronously */
struct marshal_cmd_TexGenf
{
   struct marshal_cmd_base cmd_base;
   GLenum coord;
   GLenum pname;
   GLfloat param;
};
void
_mesa_unmarshal_TexGenf(struct gl_context *ctx, const struct marshal_cmd_TexGenf *cmd)
{
   const GLenum coord = cmd->coord;
   const GLenum pname = cmd->pname;
   const GLfloat param = cmd->param;
   CALL_TexGenf(ctx->CurrentServerDispatch, (coord, pname, param));
}
void GLAPIENTRY
_mesa_marshal_TexGenf(GLenum coord, GLenum pname, GLfloat param)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexGenf);
   struct marshal_cmd_TexGenf *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexGenf, cmd_size);
   cmd->coord = coord;
   cmd->pname = pname;
   cmd->param = param;
}


/* TexGenfv: marshalled asynchronously */
struct marshal_cmd_TexGenfv
{
   struct marshal_cmd_base cmd_base;
   GLenum coord;
   GLenum pname;
   /* Next safe_mul(_mesa_texgen_enum_to_count(pname), 1 * sizeof(GLfloat)) bytes are GLfloat params[None] */
};
void
_mesa_unmarshal_TexGenfv(struct gl_context *ctx, const struct marshal_cmd_TexGenfv *cmd)
{
   const GLenum coord = cmd->coord;
   const GLenum pname = cmd->pname;
   GLfloat * params;
   const char *variable_data = (const char *) (cmd + 1);
   params = (GLfloat *) variable_data;
   CALL_TexGenfv(ctx->CurrentServerDispatch, (coord, pname, params));
}
void GLAPIENTRY
_mesa_marshal_TexGenfv(GLenum coord, GLenum pname, const GLfloat * params)
{
   GET_CURRENT_CONTEXT(ctx);
   int params_size = safe_mul(_mesa_texgen_enum_to_count(pname), 1 * sizeof(GLfloat));
   int cmd_size = sizeof(struct marshal_cmd_TexGenfv) + params_size;
   struct marshal_cmd_TexGenfv *cmd;
   if (unlikely(params_size < 0 || (params_size > 0 && !params) || (unsigned)cmd_size > MARSHAL_MAX_CMD_SIZE)) {
      _mesa_glthread_finish_before(ctx, "TexGenfv");
      CALL_TexGenfv(ctx->CurrentServerDispatch, (coord, pname, params));
      return;
   }
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexGenfv, cmd_size);
   cmd->coord = coord;
   cmd->pname = pname;
   char *variable_data = (char *) (cmd + 1);
   memcpy(variable_data, params, params_size);
}


/* TexGeni: marshalled asynchronously */
struct marshal_cmd_TexGeni
{
   struct marshal_cmd_base cmd_base;
   GLenum coord;
   GLenum pname;
   GLint param;
};
void
_mesa_unmarshal_TexGeni(struct gl_context *ctx, const struct marshal_cmd_TexGeni *cmd)
{
   const GLenum coord = cmd->coord;
   const GLenum pname = cmd->pname;
   const GLint param = cmd->param;
   CALL_TexGeni(ctx->CurrentServerDispatch, (coord, pname, param));
}
void GLAPIENTRY
_mesa_marshal_TexGeni(GLenum coord, GLenum pname, GLint param)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_TexGeni);
   struct marshal_cmd_TexGeni *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexGeni, cmd_size);
   cmd->coord = coord;
   cmd->pname = pname;
   cmd->param = param;
}


/* TexGeniv: marshalled asynchronously */
struct marshal_cmd_TexGeniv
{
   struct marshal_cmd_base cmd_base;
   GLenum coord;
   GLenum pname;
   /* Next safe_mul(_mesa_texgen_enum_to_count(pname), 1 * sizeof(GLint)) bytes are GLint params[None] */
};
void
_mesa_unmarshal_TexGeniv(struct gl_context *ctx, const struct marshal_cmd_TexGeniv *cmd)
{
   const GLenum coord = cmd->coord;
   const GLenum pname = cmd->pname;
   GLint * params;
   const char *variable_data = (const char *) (cmd + 1);
   params = (GLint *) variable_data;
   CALL_TexGeniv(ctx->CurrentServerDispatch, (coord, pname, params));
}
void GLAPIENTRY
_mesa_marshal_TexGeniv(GLenum coord, GLenum pname, const GLint * params)
{
   GET_CURRENT_CONTEXT(ctx);
   int params_size = safe_mul(_mesa_texgen_enum_to_count(pname), 1 * sizeof(GLint));
   int cmd_size = sizeof(struct marshal_cmd_TexGeniv) + params_size;
   struct marshal_cmd_TexGeniv *cmd;
   if (unlikely(params_size < 0 || (params_size > 0 && !params) || (unsigned)cmd_size > MARSHAL_MAX_CMD_SIZE)) {
      _mesa_glthread_finish_before(ctx, "TexGeniv");
      CALL_TexGeniv(ctx->CurrentServerDispatch, (coord, pname, params));
      return;
   }
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_TexGeniv, cmd_size);
   cmd->coord = coord;
   cmd->pname = pname;
   char *variable_data = (char *) (cmd + 1);
   memcpy(variable_data, params, params_size);
}


/* FeedbackBuffer: marshalled synchronously */
void GLAPIENTRY
_mesa_marshal_FeedbackBuffer(GLsizei size, GLenum type, GLfloat * buffer)
{
   GET_CURRENT_CONTEXT(ctx);
   _mesa_glthread_finish_before(ctx, "FeedbackBuffer");
   CALL_FeedbackBuffer(ctx->CurrentServerDispatch, (size, type, buffer));
}


/* SelectBuffer: marshalled synchronously */
void GLAPIENTRY
_mesa_marshal_SelectBuffer(GLsizei size, GLuint * buffer)
{
   GET_CURRENT_CONTEXT(ctx);
   _mesa_glthread_finish_before(ctx, "SelectBuffer");
   CALL_SelectBuffer(ctx->CurrentServerDispatch, (size, buffer));
}


/* RenderMode: marshalled synchronously */
GLint GLAPIENTRY
_mesa_marshal_RenderMode(GLenum mode)
{
   GET_CURRENT_CONTEXT(ctx);
   _mesa_glthread_finish_before(ctx, "RenderMode");
   return CALL_RenderMode(ctx->CurrentServerDispatch, (mode));
}


/* InitNames: marshalled asynchronously */
struct marshal_cmd_InitNames
{
   struct marshal_cmd_base cmd_base;
};
void
_mesa_unmarshal_InitNames(struct gl_context *ctx, const struct marshal_cmd_InitNames *cmd)
{
   CALL_InitNames(ctx->CurrentServerDispatch, ());
}
void GLAPIENTRY
_mesa_marshal_InitNames(void)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_InitNames);
   struct marshal_cmd_InitNames *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_InitNames, cmd_size);
   (void) cmd;
}


/* LoadName: marshalled asynchronously */
struct marshal_cmd_LoadName
{
   struct marshal_cmd_base cmd_base;
   GLuint name;
};
void
_mesa_unmarshal_LoadName(struct gl_context *ctx, const struct marshal_cmd_LoadName *cmd)
{
   const GLuint name = cmd->name;
   CALL_LoadName(ctx->CurrentServerDispatch, (name));
}
void GLAPIENTRY
_mesa_marshal_LoadName(GLuint name)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_LoadName);
   struct marshal_cmd_LoadName *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_LoadName, cmd_size);
   cmd->name = name;
}


/* PassThrough: marshalled asynchronously */
struct marshal_cmd_PassThrough
{
   struct marshal_cmd_base cmd_base;
   GLfloat token;
};
void
_mesa_unmarshal_PassThrough(struct gl_context *ctx, const struct marshal_cmd_PassThrough *cmd)
{
   const GLfloat token = cmd->token;
   CALL_PassThrough(ctx->CurrentServerDispatch, (token));
}
void GLAPIENTRY
_mesa_marshal_PassThrough(GLfloat token)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_PassThrough);
   struct marshal_cmd_PassThrough *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_PassThrough, cmd_size);
   cmd->token = token;
}


/* PopName: marshalled asynchronously */
struct marshal_cmd_PopName
{
   struct marshal_cmd_base cmd_base;
};
void
_mesa_unmarshal_PopName(struct gl_context *ctx, const struct marshal_cmd_PopName *cmd)
{
   CALL_PopName(ctx->CurrentServerDispatch, ());
}
void GLAPIENTRY
_mesa_marshal_PopName(void)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_PopName);
   struct marshal_cmd_PopName *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_PopName, cmd_size);
   (void) cmd;
}


/* PushName: marshalled asynchronously */
struct marshal_cmd_PushName
{
   struct marshal_cmd_base cmd_base;
   GLuint name;
};
void
_mesa_unmarshal_PushName(struct gl_context *ctx, const struct marshal_cmd_PushName *cmd)
{
   const GLuint name = cmd->name;
   CALL_PushName(ctx->CurrentServerDispatch, (name));
}
void GLAPIENTRY
_mesa_marshal_PushName(GLuint name)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_PushName);
   struct marshal_cmd_PushName *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_PushName, cmd_size);
   cmd->name = name;
}


/* DrawBuffer: marshalled asynchronously */
struct marshal_cmd_DrawBuffer
{
   struct marshal_cmd_base cmd_base;
   GLenum mode;
};
void
_mesa_unmarshal_DrawBuffer(struct gl_context *ctx, const struct marshal_cmd_DrawBuffer *cmd)
{
   const GLenum mode = cmd->mode;
   CALL_DrawBuffer(ctx->CurrentServerDispatch, (mode));
}
void GLAPIENTRY
_mesa_marshal_DrawBuffer(GLenum mode)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_DrawBuffer);
   struct marshal_cmd_DrawBuffer *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_DrawBuffer, cmd_size);
   cmd->mode = mode;
}


/* Clear: marshalled asynchronously */
struct marshal_cmd_Clear
{
   struct marshal_cmd_base cmd_base;
   GLbitfield mask;
};
void
_mesa_unmarshal_Clear(struct gl_context *ctx, const struct marshal_cmd_Clear *cmd)
{
   const GLbitfield mask = cmd->mask;
   CALL_Clear(ctx->CurrentServerDispatch, (mask));
}
void GLAPIENTRY
_mesa_marshal_Clear(GLbitfield mask)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Clear);
   struct marshal_cmd_Clear *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Clear, cmd_size);
   cmd->mask = mask;
}


/* ClearAccum: marshalled asynchronously */
struct marshal_cmd_ClearAccum
{
   struct marshal_cmd_base cmd_base;
   GLfloat red;
   GLfloat green;
   GLfloat blue;
   GLfloat alpha;
};
void
_mesa_unmarshal_ClearAccum(struct gl_context *ctx, const struct marshal_cmd_ClearAccum *cmd)
{
   const GLfloat red = cmd->red;
   const GLfloat green = cmd->green;
   const GLfloat blue = cmd->blue;
   const GLfloat alpha = cmd->alpha;
   CALL_ClearAccum(ctx->CurrentServerDispatch, (red, green, blue, alpha));
}
void GLAPIENTRY
_mesa_marshal_ClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_ClearAccum);
   struct marshal_cmd_ClearAccum *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_ClearAccum, cmd_size);
   cmd->red = red;
   cmd->green = green;
   cmd->blue = blue;
   cmd->alpha = alpha;
}


/* ClearIndex: marshalled asynchronously */
struct marshal_cmd_ClearIndex
{
   struct marshal_cmd_base cmd_base;
   GLfloat c;
};
void
_mesa_unmarshal_ClearIndex(struct gl_context *ctx, const struct marshal_cmd_ClearIndex *cmd)
{
   const GLfloat c = cmd->c;
   CALL_ClearIndex(ctx->CurrentServerDispatch, (c));
}
void GLAPIENTRY
_mesa_marshal_ClearIndex(GLfloat c)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_ClearIndex);
   struct marshal_cmd_ClearIndex *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_ClearIndex, cmd_size);
   cmd->c = c;
}


/* ClearColor: marshalled asynchronously */
struct marshal_cmd_ClearColor
{
   struct marshal_cmd_base cmd_base;
   GLclampf red;
   GLclampf green;
   GLclampf blue;
   GLclampf alpha;
};
void
_mesa_unmarshal_ClearColor(struct gl_context *ctx, const struct marshal_cmd_ClearColor *cmd)
{
   const GLclampf red = cmd->red;
   const GLclampf green = cmd->green;
   const GLclampf blue = cmd->blue;
   const GLclampf alpha = cmd->alpha;
   CALL_ClearColor(ctx->CurrentServerDispatch, (red, green, blue, alpha));
}
void GLAPIENTRY
_mesa_marshal_ClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_ClearColor);
   struct marshal_cmd_ClearColor *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_ClearColor, cmd_size);
   cmd->red = red;
   cmd->green = green;
   cmd->blue = blue;
   cmd->alpha = alpha;
}


/* ClearStencil: marshalled asynchronously */
struct marshal_cmd_ClearStencil
{
   struct marshal_cmd_base cmd_base;
   GLint s;
};
void
_mesa_unmarshal_ClearStencil(struct gl_context *ctx, const struct marshal_cmd_ClearStencil *cmd)
{
   const GLint s = cmd->s;
   CALL_ClearStencil(ctx->CurrentServerDispatch, (s));
}
void GLAPIENTRY
_mesa_marshal_ClearStencil(GLint s)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_ClearStencil);
   struct marshal_cmd_ClearStencil *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_ClearStencil, cmd_size);
   cmd->s = s;
}


/* ClearDepth: marshalled asynchronously */
struct marshal_cmd_ClearDepth
{
   struct marshal_cmd_base cmd_base;
   GLclampd depth;
};
void
_mesa_unmarshal_ClearDepth(struct gl_context *ctx, const struct marshal_cmd_ClearDepth *cmd)
{
   const GLclampd depth = cmd->depth;
   CALL_ClearDepth(ctx->CurrentServerDispatch, (depth));
}
void GLAPIENTRY
_mesa_marshal_ClearDepth(GLclampd depth)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_ClearDepth);
   struct marshal_cmd_ClearDepth *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_ClearDepth, cmd_size);
   cmd->depth = depth;
}


/* StencilMask: marshalled asynchronously */
struct marshal_cmd_StencilMask
{
   struct marshal_cmd_base cmd_base;
   GLuint mask;
};
void
_mesa_unmarshal_StencilMask(struct gl_context *ctx, const struct marshal_cmd_StencilMask *cmd)
{
   const GLuint mask = cmd->mask;
   CALL_StencilMask(ctx->CurrentServerDispatch, (mask));
}
void GLAPIENTRY
_mesa_marshal_StencilMask(GLuint mask)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_StencilMask);
   struct marshal_cmd_StencilMask *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_StencilMask, cmd_size);
   cmd->mask = mask;
}


/* ColorMask: marshalled asynchronously */
struct marshal_cmd_ColorMask
{
   struct marshal_cmd_base cmd_base;
   GLboolean red;
   GLboolean green;
   GLboolean blue;
   GLboolean alpha;
};
void
_mesa_unmarshal_ColorMask(struct gl_context *ctx, const struct marshal_cmd_ColorMask *cmd)
{
   const GLboolean red = cmd->red;
   const GLboolean green = cmd->green;
   const GLboolean blue = cmd->blue;
   const GLboolean alpha = cmd->alpha;
   CALL_ColorMask(ctx->CurrentServerDispatch, (red, green, blue, alpha));
}
void GLAPIENTRY
_mesa_marshal_ColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_ColorMask);
   struct marshal_cmd_ColorMask *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_ColorMask, cmd_size);
   cmd->red = red;
   cmd->green = green;
   cmd->blue = blue;
   cmd->alpha = alpha;
}


/* DepthMask: marshalled asynchronously */
struct marshal_cmd_DepthMask
{
   struct marshal_cmd_base cmd_base;
   GLboolean flag;
};
void
_mesa_unmarshal_DepthMask(struct gl_context *ctx, const struct marshal_cmd_DepthMask *cmd)
{
   const GLboolean flag = cmd->flag;
   CALL_DepthMask(ctx->CurrentServerDispatch, (flag));
}
void GLAPIENTRY
_mesa_marshal_DepthMask(GLboolean flag)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_DepthMask);
   struct marshal_cmd_DepthMask *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_DepthMask, cmd_size);
   cmd->flag = flag;
}


/* IndexMask: marshalled asynchronously */
struct marshal_cmd_IndexMask
{
   struct marshal_cmd_base cmd_base;
   GLuint mask;
};
void
_mesa_unmarshal_IndexMask(struct gl_context *ctx, const struct marshal_cmd_IndexMask *cmd)
{
   const GLuint mask = cmd->mask;
   CALL_IndexMask(ctx->CurrentServerDispatch, (mask));
}
void GLAPIENTRY
_mesa_marshal_IndexMask(GLuint mask)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_IndexMask);
   struct marshal_cmd_IndexMask *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_IndexMask, cmd_size);
   cmd->mask = mask;
}


/* Accum: marshalled asynchronously */
struct marshal_cmd_Accum
{
   struct marshal_cmd_base cmd_base;
   GLenum op;
   GLfloat value;
};
void
_mesa_unmarshal_Accum(struct gl_context *ctx, const struct marshal_cmd_Accum *cmd)
{
   const GLenum op = cmd->op;
   const GLfloat value = cmd->value;
   CALL_Accum(ctx->CurrentServerDispatch, (op, value));
}
void GLAPIENTRY
_mesa_marshal_Accum(GLenum op, GLfloat value)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Accum);
   struct marshal_cmd_Accum *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Accum, cmd_size);
   cmd->op = op;
   cmd->value = value;
}


/* Disable: marshalled asynchronously */
struct marshal_cmd_Disable
{
   struct marshal_cmd_base cmd_base;
   GLenum cap;
};
void
_mesa_unmarshal_Disable(struct gl_context *ctx, const struct marshal_cmd_Disable *cmd)
{
   const GLenum cap = cmd->cap;
   CALL_Disable(ctx->CurrentServerDispatch, (cap));
}
void GLAPIENTRY
_mesa_marshal_Disable(GLenum cap)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Disable);
   struct marshal_cmd_Disable *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Disable, cmd_size);
   cmd->cap = cap;
   if (cap == GL_PRIMITIVE_RESTART || cap == GL_PRIMITIVE_RESTART_FIXED_INDEX) _mesa_glthread_set_prim_restart(ctx, cap, false);
}


/* Enable: marshalled asynchronously */
struct marshal_cmd_Enable
{
   struct marshal_cmd_base cmd_base;
   GLenum cap;
};
void
_mesa_unmarshal_Enable(struct gl_context *ctx, const struct marshal_cmd_Enable *cmd)
{
   const GLenum cap = cmd->cap;
   CALL_Enable(ctx->CurrentServerDispatch, (cap));
}
void GLAPIENTRY
_mesa_marshal_Enable(GLenum cap)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Enable);
   struct marshal_cmd_Enable *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Enable, cmd_size);
   cmd->cap = cap;
   if (cap == GL_PRIMITIVE_RESTART || cap == GL_PRIMITIVE_RESTART_FIXED_INDEX) { _mesa_glthread_set_prim_restart(ctx, cap, true); } else if (cap == GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB) { _mesa_glthread_disable(ctx, "Enable(DEBUG_OUTPUT_SYNCHRONOUS)"); }
}


/* Finish: marshalled synchronously */
void GLAPIENTRY
_mesa_marshal_Finish(void)
{
   GET_CURRENT_CONTEXT(ctx);
   _mesa_glthread_finish_before(ctx, "Finish");
   CALL_Finish(ctx->CurrentServerDispatch, ());
}


/* Flush: marshalled asynchronously */
struct marshal_cmd_Flush
{
   struct marshal_cmd_base cmd_base;
};
void
_mesa_unmarshal_Flush(struct gl_context *ctx, const struct marshal_cmd_Flush *cmd)
{
   CALL_Flush(ctx->CurrentServerDispatch, ());
}
void GLAPIENTRY
_mesa_marshal_Flush(void)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_Flush);
   struct marshal_cmd_Flush *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_Flush, cmd_size);
   (void) cmd;
   _mesa_glthread_flush_batch(ctx); if (ctx->Shared->RefCount > 1) _mesa_glthread_finish(ctx);
}


/* PopAttrib: marshalled asynchronously */
struct marshal_cmd_PopAttrib
{
   struct marshal_cmd_base cmd_base;
};
void
_mesa_unmarshal_PopAttrib(struct gl_context *ctx, const struct marshal_cmd_PopAttrib *cmd)
{
   CALL_PopAttrib(ctx->CurrentServerDispatch, ());
}
void GLAPIENTRY
_mesa_marshal_PopAttrib(void)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_PopAttrib);
   struct marshal_cmd_PopAttrib *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_PopAttrib, cmd_size);
   (void) cmd;
}


/* PushAttrib: marshalled asynchronously */
struct marshal_cmd_PushAttrib
{
   struct marshal_cmd_base cmd_base;
   GLbitfield mask;
};
void
_mesa_unmarshal_PushAttrib(struct gl_context *ctx, const struct marshal_cmd_PushAttrib *cmd)
{
   const GLbitfield mask = cmd->mask;
   CALL_PushAttrib(ctx->CurrentServerDispatch, (mask));
}
void GLAPIENTRY
_mesa_marshal_PushAttrib(GLbitfield mask)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_PushAttrib);
   struct marshal_cmd_PushAttrib *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_PushAttrib, cmd_size);
   cmd->mask = mask;
}


/* Map1d: marshalled synchronously */
void GLAPIENTRY
_mesa_marshal_Map1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble * points)
{
   GET_CURRENT_CONTEXT(ctx);
   _mesa_glthread_finish_before(ctx, "Map1d");
   CALL_Map1d(ctx->CurrentServerDispatch, (target, u1, u2, stride, order, points));
}


/* Map1f: marshalled synchronously */
void GLAPIENTRY
_mesa_marshal_Map1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat * points)
{
   GET_CURRENT_CONTEXT(ctx);
   _mesa_glthread_finish_before(ctx, "Map1f");
   CALL_Map1f(ctx->CurrentServerDispatch, (target, u1, u2, stride, order, points));
}


/* Map2d: marshalled synchronously */
void GLAPIENTRY
_mesa_marshal_Map2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble * points)
{
   GET_CURRENT_CONTEXT(ctx);
   _mesa_glthread_finish_before(ctx, "Map2d");
   CALL_Map2d(ctx->CurrentServerDispatch, (target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points));
}


/* Map2f: marshalled synchronously */
void GLAPIENTRY
_mesa_marshal_Map2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat * points)
{
   GET_CURRENT_CONTEXT(ctx);
   _mesa_glthread_finish_before(ctx, "Map2f");
   CALL_Map2f(ctx->CurrentServerDispatch, (target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points));
}


/* MapGrid1d: marshalled asynchronously */
struct marshal_cmd_MapGrid1d
{
   struct marshal_cmd_base cmd_base;
   GLint un;
   GLdouble u1;
   GLdouble u2;
};
void
_mesa_unmarshal_MapGrid1d(struct gl_context *ctx, const struct marshal_cmd_MapGrid1d *cmd)
{
   const GLint un = cmd->un;
   const GLdouble u1 = cmd->u1;
   const GLdouble u2 = cmd->u2;
   CALL_MapGrid1d(ctx->CurrentServerDispatch, (un, u1, u2));
}
void GLAPIENTRY
_mesa_marshal_MapGrid1d(GLint un, GLdouble u1, GLdouble u2)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_MapGrid1d);
   struct marshal_cmd_MapGrid1d *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_MapGrid1d, cmd_size);
   cmd->un = un;
   cmd->u1 = u1;
   cmd->u2 = u2;
}


/* MapGrid1f: marshalled asynchronously */
struct marshal_cmd_MapGrid1f
{
   struct marshal_cmd_base cmd_base;
   GLint un;
   GLfloat u1;
   GLfloat u2;
};
void
_mesa_unmarshal_MapGrid1f(struct gl_context *ctx, const struct marshal_cmd_MapGrid1f *cmd)
{
   const GLint un = cmd->un;
   const GLfloat u1 = cmd->u1;
   const GLfloat u2 = cmd->u2;
   CALL_MapGrid1f(ctx->CurrentServerDispatch, (un, u1, u2));
}
void GLAPIENTRY
_mesa_marshal_MapGrid1f(GLint un, GLfloat u1, GLfloat u2)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_MapGrid1f);
   struct marshal_cmd_MapGrid1f *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_MapGrid1f, cmd_size);
   cmd->un = un;
   cmd->u1 = u1;
   cmd->u2 = u2;
}


/* MapGrid2d: marshalled asynchronously */
struct marshal_cmd_MapGrid2d
{
   struct marshal_cmd_base cmd_base;
   GLint un;
   GLint vn;
   GLdouble u1;
   GLdouble u2;
   GLdouble v1;
   GLdouble v2;
};
void
_mesa_unmarshal_MapGrid2d(struct gl_context *ctx, const struct marshal_cmd_MapGrid2d *cmd)
{
   const GLint un = cmd->un;
   const GLdouble u1 = cmd->u1;
   const GLdouble u2 = cmd->u2;
   const GLint vn = cmd->vn;
   const GLdouble v1 = cmd->v1;
   const GLdouble v2 = cmd->v2;
   CALL_MapGrid2d(ctx->CurrentServerDispatch, (un, u1, u2, vn, v1, v2));
}
void GLAPIENTRY
_mesa_marshal_MapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_MapGrid2d);
   struct marshal_cmd_MapGrid2d *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_MapGrid2d, cmd_size);
   cmd->un = un;
   cmd->u1 = u1;
   cmd->u2 = u2;
   cmd->vn = vn;
   cmd->v1 = v1;
   cmd->v2 = v2;
}


/* MapGrid2f: marshalled asynchronously */
struct marshal_cmd_MapGrid2f
{
   struct marshal_cmd_base cmd_base;
   GLint un;
   GLfloat u1;
   GLfloat u2;
   GLint vn;
   GLfloat v1;
   GLfloat v2;
};
void
_mesa_unmarshal_MapGrid2f(struct gl_context *ctx, const struct marshal_cmd_MapGrid2f *cmd)
{
   const GLint un = cmd->un;
   const GLfloat u1 = cmd->u1;
   const GLfloat u2 = cmd->u2;
   const GLint vn = cmd->vn;
   const GLfloat v1 = cmd->v1;
   const GLfloat v2 = cmd->v2;
   CALL_MapGrid2f(ctx->CurrentServerDispatch, (un, u1, u2, vn, v1, v2));
}
void GLAPIENTRY
_mesa_marshal_MapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_MapGrid2f);
   struct marshal_cmd_MapGrid2f *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_MapGrid2f, cmd_size);
   cmd->un = un;
   cmd->u1 = u1;
   cmd->u2 = u2;
   cmd->vn = vn;
   cmd->v1 = v1;
   cmd->v2 = v2;
}


/* EvalCoord1d: marshalled asynchronously */
struct marshal_cmd_EvalCoord1d
{
   struct marshal_cmd_base cmd_base;
   GLdouble u;
};
void
_mesa_unmarshal_EvalCoord1d(struct gl_context *ctx, const struct marshal_cmd_EvalCoord1d *cmd)
{
   const GLdouble u = cmd->u;
   CALL_EvalCoord1d(ctx->CurrentServerDispatch, (u));
}
void GLAPIENTRY
_mesa_marshal_EvalCoord1d(GLdouble u)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_EvalCoord1d);
   struct marshal_cmd_EvalCoord1d *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_EvalCoord1d, cmd_size);
   cmd->u = u;
}


/* EvalCoord1dv: marshalled asynchronously */
struct marshal_cmd_EvalCoord1dv
{
   struct marshal_cmd_base cmd_base;
   GLdouble u[1];
};
void
_mesa_unmarshal_EvalCoord1dv(struct gl_context *ctx, const struct marshal_cmd_EvalCoord1dv *cmd)
{
   const GLdouble * u = cmd->u;
   CALL_EvalCoord1dv(ctx->CurrentServerDispatch, (u));
}
void GLAPIENTRY
_mesa_marshal_EvalCoord1dv(const GLdouble * u)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_EvalCoord1dv);
   struct marshal_cmd_EvalCoord1dv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_EvalCoord1dv, cmd_size);
   memcpy(cmd->u, u, 1 * sizeof(GLdouble));
}


/* EvalCoord1f: marshalled asynchronously */
struct marshal_cmd_EvalCoord1f
{
   struct marshal_cmd_base cmd_base;
   GLfloat u;
};
void
_mesa_unmarshal_EvalCoord1f(struct gl_context *ctx, const struct marshal_cmd_EvalCoord1f *cmd)
{
   const GLfloat u = cmd->u;
   CALL_EvalCoord1f(ctx->CurrentServerDispatch, (u));
}
void GLAPIENTRY
_mesa_marshal_EvalCoord1f(GLfloat u)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_EvalCoord1f);
   struct marshal_cmd_EvalCoord1f *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_EvalCoord1f, cmd_size);
   cmd->u = u;
}


/* EvalCoord1fv: marshalled asynchronously */
struct marshal_cmd_EvalCoord1fv
{
   struct marshal_cmd_base cmd_base;
   GLfloat u[1];
};
void
_mesa_unmarshal_EvalCoord1fv(struct gl_context *ctx, const struct marshal_cmd_EvalCoord1fv *cmd)
{
   const GLfloat * u = cmd->u;
   CALL_EvalCoord1fv(ctx->CurrentServerDispatch, (u));
}
void GLAPIENTRY
_mesa_marshal_EvalCoord1fv(const GLfloat * u)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_EvalCoord1fv);
   struct marshal_cmd_EvalCoord1fv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_EvalCoord1fv, cmd_size);
   memcpy(cmd->u, u, 1 * sizeof(GLfloat));
}


/* EvalCoord2d: marshalled asynchronously */
struct marshal_cmd_EvalCoord2d
{
   struct marshal_cmd_base cmd_base;
   GLdouble u;
   GLdouble v;
};
void
_mesa_unmarshal_EvalCoord2d(struct gl_context *ctx, const struct marshal_cmd_EvalCoord2d *cmd)
{
   const GLdouble u = cmd->u;
   const GLdouble v = cmd->v;
   CALL_EvalCoord2d(ctx->CurrentServerDispatch, (u, v));
}
void GLAPIENTRY
_mesa_marshal_EvalCoord2d(GLdouble u, GLdouble v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_EvalCoord2d);
   struct marshal_cmd_EvalCoord2d *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_EvalCoord2d, cmd_size);
   cmd->u = u;
   cmd->v = v;
}


/* EvalCoord2dv: marshalled asynchronously */
struct marshal_cmd_EvalCoord2dv
{
   struct marshal_cmd_base cmd_base;
   GLdouble u[2];
};
void
_mesa_unmarshal_EvalCoord2dv(struct gl_context *ctx, const struct marshal_cmd_EvalCoord2dv *cmd)
{
   const GLdouble * u = cmd->u;
   CALL_EvalCoord2dv(ctx->CurrentServerDispatch, (u));
}
void GLAPIENTRY
_mesa_marshal_EvalCoord2dv(const GLdouble * u)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_EvalCoord2dv);
   struct marshal_cmd_EvalCoord2dv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_EvalCoord2dv, cmd_size);
   memcpy(cmd->u, u, 2 * sizeof(GLdouble));
}


/* EvalCoord2f: marshalled asynchronously */
struct marshal_cmd_EvalCoord2f
{
   struct marshal_cmd_base cmd_base;
   GLfloat u;
   GLfloat v;
};
void
_mesa_unmarshal_EvalCoord2f(struct gl_context *ctx, const struct marshal_cmd_EvalCoord2f *cmd)
{
   const GLfloat u = cmd->u;
   const GLfloat v = cmd->v;
   CALL_EvalCoord2f(ctx->CurrentServerDispatch, (u, v));
}
void GLAPIENTRY
_mesa_marshal_EvalCoord2f(GLfloat u, GLfloat v)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_EvalCoord2f);
   struct marshal_cmd_EvalCoord2f *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_EvalCoord2f, cmd_size);
   cmd->u = u;
   cmd->v = v;
}


/* EvalCoord2fv: marshalled asynchronously */
struct marshal_cmd_EvalCoord2fv
{
   struct marshal_cmd_base cmd_base;
   GLfloat u[2];
};
void
_mesa_unmarshal_EvalCoord2fv(struct gl_context *ctx, const struct marshal_cmd_EvalCoord2fv *cmd)
{
   const GLfloat * u = cmd->u;
   CALL_EvalCoord2fv(ctx->CurrentServerDispatch, (u));
}
void GLAPIENTRY
_mesa_marshal_EvalCoord2fv(const GLfloat * u)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_EvalCoord2fv);
   struct marshal_cmd_EvalCoord2fv *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_EvalCoord2fv, cmd_size);
   memcpy(cmd->u, u, 2 * sizeof(GLfloat));
}


/* EvalMesh1: marshalled asynchronously */
struct marshal_cmd_EvalMesh1
{
   struct marshal_cmd_base cmd_base;
   GLenum mode;
   GLint i1;
   GLint i2;
};
void
_mesa_unmarshal_EvalMesh1(struct gl_context *ctx, const struct marshal_cmd_EvalMesh1 *cmd)
{
   const GLenum mode = cmd->mode;
   const GLint i1 = cmd->i1;
   const GLint i2 = cmd->i2;
   CALL_EvalMesh1(ctx->CurrentServerDispatch, (mode, i1, i2));
}
void GLAPIENTRY
_mesa_marshal_EvalMesh1(GLenum mode, GLint i1, GLint i2)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_EvalMesh1);
   struct marshal_cmd_EvalMesh1 *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_EvalMesh1, cmd_size);
   cmd->mode = mode;
   cmd->i1 = i1;
   cmd->i2 = i2;
}


/* EvalPoint1: marshalled asynchronously */
struct marshal_cmd_EvalPoint1
{
   struct marshal_cmd_base cmd_base;
   GLint i;
};
void
_mesa_unmarshal_EvalPoint1(struct gl_context *ctx, const struct marshal_cmd_EvalPoint1 *cmd)
{
   const GLint i = cmd->i;
   CALL_EvalPoint1(ctx->CurrentServerDispatch, (i));
}
void GLAPIENTRY
_mesa_marshal_EvalPoint1(GLint i)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_EvalPoint1);
   struct marshal_cmd_EvalPoint1 *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_EvalPoint1, cmd_size);
   cmd->i = i;
}


/* EvalMesh2: marshalled asynchronously */
struct marshal_cmd_EvalMesh2
{
   struct marshal_cmd_base cmd_base;
   GLenum mode;
   GLint i1;
   GLint i2;
   GLint j1;
   GLint j2;
};
void
_mesa_unmarshal_EvalMesh2(struct gl_context *ctx, const struct marshal_cmd_EvalMesh2 *cmd)
{
   const GLenum mode = cmd->mode;
   const GLint i1 = cmd->i1;
   const GLint i2 = cmd->i2;
   const GLint j1 = cmd->j1;
   const GLint j2 = cmd->j2;
   CALL_EvalMesh2(ctx->CurrentServerDispatch, (mode, i1, i2, j1, j2));
}
void GLAPIENTRY
_mesa_marshal_EvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_EvalMesh2);
   struct marshal_cmd_EvalMesh2 *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_EvalMesh2, cmd_size);
   cmd->mode = mode;
   cmd->i1 = i1;
   cmd->i2 = i2;
   cmd->j1 = j1;
   cmd->j2 = j2;
}


/* EvalPoint2: marshalled asynchronously */
struct marshal_cmd_EvalPoint2
{
   struct marshal_cmd_base cmd_base;
   GLint i;
   GLint j;
};
void
_mesa_unmarshal_EvalPoint2(struct gl_context *ctx, const struct marshal_cmd_EvalPoint2 *cmd)
{
   const GLint i = cmd->i;
   const GLint j = cmd->j;
   CALL_EvalPoint2(ctx->CurrentServerDispatch, (i, j));
}
void GLAPIENTRY
_mesa_marshal_EvalPoint2(GLint i, GLint j)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_EvalPoint2);
   struct marshal_cmd_EvalPoint2 *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_EvalPoint2, cmd_size);
   cmd->i = i;
   cmd->j = j;
}


/* AlphaFunc: marshalled asynchronously */
struct marshal_cmd_AlphaFunc
{
   struct marshal_cmd_base cmd_base;
   GLenum func;
   GLclampf ref;
};
void
_mesa_unmarshal_AlphaFunc(struct gl_context *ctx, const struct marshal_cmd_AlphaFunc *cmd)
{
   const GLenum func = cmd->func;
   const GLclampf ref = cmd->ref;
   CALL_AlphaFunc(ctx->CurrentServerDispatch, (func, ref));
}
void GLAPIENTRY
_mesa_marshal_AlphaFunc(GLenum func, GLclampf ref)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_AlphaFunc);
   struct marshal_cmd_AlphaFunc *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_AlphaFunc, cmd_size);
   cmd->func = func;
   cmd->ref = ref;
}


/* BlendFunc: marshalled asynchronously */
struct marshal_cmd_BlendFunc
{
   struct marshal_cmd_base cmd_base;
   GLenum sfactor;
   GLenum dfactor;
};
void
_mesa_unmarshal_BlendFunc(struct gl_context *ctx, const struct marshal_cmd_BlendFunc *cmd)
{
   const GLenum sfactor = cmd->sfactor;
   const GLenum dfactor = cmd->dfactor;
   CALL_BlendFunc(ctx->CurrentServerDispatch, (sfactor, dfactor));
}
void GLAPIENTRY
_mesa_marshal_BlendFunc(GLenum sfactor, GLenum dfactor)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_BlendFunc);
   struct marshal_cmd_BlendFunc *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_BlendFunc, cmd_size);
   cmd->sfactor = sfactor;
   cmd->dfactor = dfactor;
}


/* LogicOp: marshalled asynchronously */
struct marshal_cmd_LogicOp
{
   struct marshal_cmd_base cmd_base;
   GLenum opcode;
};
void
_mesa_unmarshal_LogicOp(struct gl_context *ctx, const struct marshal_cmd_LogicOp *cmd)
{
   const GLenum opcode = cmd->opcode;
   CALL_LogicOp(ctx->CurrentServerDispatch, (opcode));
}
void GLAPIENTRY
_mesa_marshal_LogicOp(GLenum opcode)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_LogicOp);
   struct marshal_cmd_LogicOp *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_LogicOp, cmd_size);
   cmd->opcode = opcode;
}


/* StencilFunc: marshalled asynchronously */
struct marshal_cmd_StencilFunc
{
   struct marshal_cmd_base cmd_base;
   GLenum func;
   GLint ref;
   GLuint mask;
};
void
_mesa_unmarshal_StencilFunc(struct gl_context *ctx, const struct marshal_cmd_StencilFunc *cmd)
{
   const GLenum func = cmd->func;
   const GLint ref = cmd->ref;
   const GLuint mask = cmd->mask;
   CALL_StencilFunc(ctx->CurrentServerDispatch, (func, ref, mask));
}
void GLAPIENTRY
_mesa_marshal_StencilFunc(GLenum func, GLint ref, GLuint mask)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_StencilFunc);
   struct marshal_cmd_StencilFunc *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_StencilFunc, cmd_size);
   cmd->func = func;
   cmd->ref = ref;
   cmd->mask = mask;
}


/* StencilOp: marshalled asynchronously */
struct marshal_cmd_StencilOp
{
   struct marshal_cmd_base cmd_base;
   GLenum fail;
   GLenum zfail;
   GLenum zpass;
};
void
_mesa_unmarshal_StencilOp(struct gl_context *ctx, const struct marshal_cmd_StencilOp *cmd)
{
   const GLenum fail = cmd->fail;
   const GLenum zfail = cmd->zfail;
   const GLenum zpass = cmd->zpass;
   CALL_StencilOp(ctx->CurrentServerDispatch, (fail, zfail, zpass));
}
void GLAPIENTRY
_mesa_marshal_StencilOp(GLenum fail, GLenum zfail, GLenum zpass)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_StencilOp);
   struct marshal_cmd_StencilOp *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_StencilOp, cmd_size);
   cmd->fail = fail;
   cmd->zfail = zfail;
   cmd->zpass = zpass;
}


/* DepthFunc: marshalled asynchronously */
struct marshal_cmd_DepthFunc
{
   struct marshal_cmd_base cmd_base;
   GLenum func;
};
void
_mesa_unmarshal_DepthFunc(struct gl_context *ctx, const struct marshal_cmd_DepthFunc *cmd)
{
   const GLenum func = cmd->func;
   CALL_DepthFunc(ctx->CurrentServerDispatch, (func));
}
void GLAPIENTRY
_mesa_marshal_DepthFunc(GLenum func)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_DepthFunc);
   struct marshal_cmd_DepthFunc *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_DepthFunc, cmd_size);
   cmd->func = func;
}


/* PixelZoom: marshalled asynchronously */
struct marshal_cmd_PixelZoom
{
   struct marshal_cmd_base cmd_base;
   GLfloat xfactor;
   GLfloat yfactor;
};
void
_mesa_unmarshal_PixelZoom(struct gl_context *ctx, const struct marshal_cmd_PixelZoom *cmd)
{
   const GLfloat xfactor = cmd->xfactor;
   const GLfloat yfactor = cmd->yfactor;
   CALL_PixelZoom(ctx->CurrentServerDispatch, (xfactor, yfactor));
}
void GLAPIENTRY
_mesa_marshal_PixelZoom(GLfloat xfactor, GLfloat yfactor)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_PixelZoom);
   struct marshal_cmd_PixelZoom *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_PixelZoom, cmd_size);
   cmd->xfactor = xfactor;
   cmd->yfactor = yfactor;
}


/* PixelTransferf: marshalled asynchronously */
struct marshal_cmd_PixelTransferf
{
   struct marshal_cmd_base cmd_base;
   GLenum pname;
   GLfloat param;
};
void
_mesa_unmarshal_PixelTransferf(struct gl_context *ctx, const struct marshal_cmd_PixelTransferf *cmd)
{
   const GLenum pname = cmd->pname;
   const GLfloat param = cmd->param;
   CALL_PixelTransferf(ctx->CurrentServerDispatch, (pname, param));
}
void GLAPIENTRY
_mesa_marshal_PixelTransferf(GLenum pname, GLfloat param)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_PixelTransferf);
   struct marshal_cmd_PixelTransferf *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_PixelTransferf, cmd_size);
   cmd->pname = pname;
   cmd->param = param;
}


/* PixelTransferi: marshalled asynchronously */
struct marshal_cmd_PixelTransferi
{
   struct marshal_cmd_base cmd_base;
   GLenum pname;
   GLint param;
};
void
_mesa_unmarshal_PixelTransferi(struct gl_context *ctx, const struct marshal_cmd_PixelTransferi *cmd)
{
   const GLenum pname = cmd->pname;
   const GLint param = cmd->param;
   CALL_PixelTransferi(ctx->CurrentServerDispatch, (pname, param));
}
void GLAPIENTRY
_mesa_marshal_PixelTransferi(GLenum pname, GLint param)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_PixelTransferi);
   struct marshal_cmd_PixelTransferi *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_PixelTransferi, cmd_size);
   cmd->pname = pname;
   cmd->param = param;
}


/* PixelStoref: marshalled asynchronously */
struct marshal_cmd_PixelStoref
{
   struct marshal_cmd_base cmd_base;
   GLenum pname;
   GLfloat param;
};
void
_mesa_unmarshal_PixelStoref(struct gl_context *ctx, const struct marshal_cmd_PixelStoref *cmd)
{
   const GLenum pname = cmd->pname;
   const GLfloat param = cmd->param;
   CALL_PixelStoref(ctx->CurrentServerDispatch, (pname, param));
}
void GLAPIENTRY
_mesa_marshal_PixelStoref(GLenum pname, GLfloat param)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_PixelStoref);
   struct marshal_cmd_PixelStoref *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_PixelStoref, cmd_size);
   cmd->pname = pname;
   cmd->param = param;
}


/* PixelStorei: marshalled asynchronously */
struct marshal_cmd_PixelStorei
{
   struct marshal_cmd_base cmd_base;
   GLenum pname;
   GLint param;
};
void
_mesa_unmarshal_PixelStorei(struct gl_context *ctx, const struct marshal_cmd_PixelStorei *cmd)
{
   const GLenum pname = cmd->pname;
   const GLint param = cmd->param;
   CALL_PixelStorei(ctx->CurrentServerDispatch, (pname, param));
}
void GLAPIENTRY
_mesa_marshal_PixelStorei(GLenum pname, GLint param)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_PixelStorei);
   struct marshal_cmd_PixelStorei *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_PixelStorei, cmd_size);
   cmd->pname = pname;
   cmd->param = param;
}


/* PixelMapfv: marshalled synchronously */
void GLAPIENTRY
_mesa_marshal_PixelMapfv(GLenum map, GLsizei mapsize, const GLfloat * values)
{
   GET_CURRENT_CONTEXT(ctx);
   _mesa_glthread_finish_before(ctx, "PixelMapfv");
   CALL_PixelMapfv(ctx->CurrentServerDispatch, (map, mapsize, values));
}


/* PixelMapuiv: marshalled synchronously */
void GLAPIENTRY
_mesa_marshal_PixelMapuiv(GLenum map, GLsizei mapsize, const GLuint * values)
{
   GET_CURRENT_CONTEXT(ctx);
   _mesa_glthread_finish_before(ctx, "PixelMapuiv");
   CALL_PixelMapuiv(ctx->CurrentServerDispatch, (map, mapsize, values));
}


/* PixelMapusv: marshalled synchronously */
void GLAPIENTRY
_mesa_marshal_PixelMapusv(GLenum map, GLsizei mapsize, const GLushort * values)
{
   GET_CURRENT_CONTEXT(ctx);
   _mesa_glthread_finish_before(ctx, "PixelMapusv");
   CALL_PixelMapusv(ctx->CurrentServerDispatch, (map, mapsize, values));
}


/* ReadBuffer: marshalled asynchronously */
struct marshal_cmd_ReadBuffer
{
   struct marshal_cmd_base cmd_base;
   GLenum mode;
};
void
_mesa_unmarshal_ReadBuffer(struct gl_context *ctx, const struct marshal_cmd_ReadBuffer *cmd)
{
   const GLenum mode = cmd->mode;
   CALL_ReadBuffer(ctx->CurrentServerDispatch, (mode));
}
void GLAPIENTRY
_mesa_marshal_ReadBuffer(GLenum mode)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_ReadBuffer);
   struct marshal_cmd_ReadBuffer *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_ReadBuffer, cmd_size);
   cmd->mode = mode;
}


/* CopyPixels: marshalled asynchronously */
struct marshal_cmd_CopyPixels
{
   struct marshal_cmd_base cmd_base;
   GLint x;
   GLint y;
   GLsizei width;
   GLsizei height;
   GLenum type;
};
void
_mesa_unmarshal_CopyPixels(struct gl_context *ctx, const struct marshal_cmd_CopyPixels *cmd)
{
   const GLint x = cmd->x;
   const GLint y = cmd->y;
   const GLsizei width = cmd->width;
   const GLsizei height = cmd->height;
   const GLenum type = cmd->type;
   CALL_CopyPixels(ctx->CurrentServerDispatch, (x, y, width, height, type));
}
void GLAPIENTRY
_mesa_marshal_CopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type)
{
   GET_CURRENT_CONTEXT(ctx);
   int cmd_size = sizeof(struct marshal_cmd_CopyPixels);
   struct marshal_cmd_CopyPixels *cmd;
   cmd = _mesa_glthread_allocate_command(ctx, DISPATCH_CMD_CopyPixels, cmd_size);
   cmd->x = x;
   cmd->y = y;
   cmd->width = width;
   cmd->height = height;
   cmd->type = type;
}


/* ReadPixels: marshalled synchronously */
void GLAPIENTRY
_mesa_marshal_ReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * pixels)
{
   GET_CURRENT_CONTEXT(ctx);
   _mesa_glthread_finish_before(ctx, "ReadPixels");
   CALL_ReadPixels(ctx->CurrentServerDispatch, (x, y, width, height, format, type, pixels));
}


/* DrawPixels: marshalled synchronously */
void GLAPIENTRY
_mesa_marshal_DrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels)
{
   GET_CURRENT_CONTEXT(ctx);
   _mesa_glthread_finish_before(ctx, "DrawPixels");
   CALL_DrawPixels(ctx->CurrentServerDispatch, (width, height, format, type, pixels));
}


/* GetBooleanv: marshalled synchronously */
void GLAPIENTRY
_mesa_marshal_GetBooleanv(GLenum pname, GLboolean * params)
{
   GET_CURRENT_CONTEXT(ctx);
   _mesa_glthread_finish_before(ctx, "GetBooleanv");
   CALL_GetBooleanv(ctx->CurrentServerDispatch, (pname, params));
}


/* GetClipPlane: marshalled synchronously */
void GLAPIENTRY
_mesa_marshal_GetClipPlane(GLenum plane, GLdouble * equation)
{
   GET_CURRENT_CONTEXT(ctx);
   _mesa_glthread_finish_before(ctx, "GetClipPlane");
   CALL_GetClipPlane(ctx->CurrentServerDispatch, (plane, equation));
}


/* GetDoublev: marshalled synchronously */
void GLAPIENTRY
_mesa_marshal_GetDoublev(GLenum pname, GLdouble * params)
{
   GET_CURRENT_CONTEXT(ctx);
   _mesa_glthread_finish_before(ctx, "GetDoublev");
   CALL_GetDoublev(ctx->CurrentServerDispatch, (pname, params));
}


/* GetError: marshalled synchronously */
GLenum GLAPIENTRY
_mesa_marshal_GetError(void)
{
   GET_CURRENT_CONTEXT(ctx);
   _mesa_glthread_finish_before(ctx, "GetError");
   return CALL_GetError(ctx->CurrentServerDispatch, ());
}


/* GetFloatv: marshalled synchronously */
void GLAPIENTRY
_mesa_marshal_GetFloatv(GLenum pname, GLfloat * params)
{
   GET_CURRENT_CONTEXT(ctx);
   _mesa_glthread_finish_before(ctx, "GetFloatv");
   CALL_GetFloatv(ctx->CurrentServerDispatch, (pname, params));
}


/* GetIntegerv: marshalled synchronously */
void GLAPIENTRY
_mesa_marshal_GetIntegerv(GLenum pname, GLint * params)
{
   GET_CURRENT_CONTEXT(ctx);
   _mesa_glthread_finish_before(ctx, "GetIntegerv");
   CALL_GetIntegerv(ctx->CurrentServerDispatch, (pname, params));
}


