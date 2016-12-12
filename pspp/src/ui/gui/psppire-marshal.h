
#ifndef __psppire_marshal_MARSHAL_H__
#define __psppire_marshal_MARSHAL_H__

#include	<glib-object.h>

G_BEGIN_DECLS

/* BOOLEAN:BOOLEAN (src/ui/gui/marshaller-list:3) */
extern void psppire_marshal_BOOLEAN__BOOLEAN (GClosure     *closure,
                                              GValue       *return_value,
                                              guint         n_param_values,
                                              const GValue *param_values,
                                              gpointer      invocation_hint,
                                              gpointer      marshal_data);

/* BOOLEAN:BOXED (src/ui/gui/marshaller-list:4) */
extern void psppire_marshal_BOOLEAN__BOXED (GClosure     *closure,
                                            GValue       *return_value,
                                            guint         n_param_values,
                                            const GValue *param_values,
                                            gpointer      invocation_hint,
                                            gpointer      marshal_data);

/* BOOLEAN:ENUM (src/ui/gui/marshaller-list:5) */
extern void psppire_marshal_BOOLEAN__ENUM (GClosure     *closure,
                                           GValue       *return_value,
                                           guint         n_param_values,
                                           const GValue *param_values,
                                           gpointer      invocation_hint,
                                           gpointer      marshal_data);

/* BOOLEAN:ENUM,INT (src/ui/gui/marshaller-list:6) */
extern void psppire_marshal_BOOLEAN__ENUM_INT (GClosure     *closure,
                                               GValue       *return_value,
                                               guint         n_param_values,
                                               const GValue *param_values,
                                               gpointer      invocation_hint,
                                               gpointer      marshal_data);

/* BOOLEAN:INT (src/ui/gui/marshaller-list:7) */
extern void psppire_marshal_BOOLEAN__INT (GClosure     *closure,
                                          GValue       *return_value,
                                          guint         n_param_values,
                                          const GValue *param_values,
                                          gpointer      invocation_hint,
                                          gpointer      marshal_data);

/* BOOLEAN:OBJECT (src/ui/gui/marshaller-list:8) */
extern void psppire_marshal_BOOLEAN__OBJECT (GClosure     *closure,
                                             GValue       *return_value,
                                             guint         n_param_values,
                                             const GValue *param_values,
                                             gpointer      invocation_hint,
                                             gpointer      marshal_data);

/* BOOLEAN:VOID (src/ui/gui/marshaller-list:9) */
extern void psppire_marshal_BOOLEAN__VOID (GClosure     *closure,
                                           GValue       *return_value,
                                           guint         n_param_values,
                                           const GValue *param_values,
                                           gpointer      invocation_hint,
                                           gpointer      marshal_data);

/* VOID:BOXED,OBJECT (src/ui/gui/marshaller-list:10) */
extern void psppire_marshal_VOID__BOXED_OBJECT (GClosure     *closure,
                                                GValue       *return_value,
                                                guint         n_param_values,
                                                const GValue *param_values,
                                                gpointer      invocation_hint,
                                                gpointer      marshal_data);

/* VOID:INT,INT (src/ui/gui/marshaller-list:11) */
extern void psppire_marshal_VOID__INT_INT (GClosure     *closure,
                                           GValue       *return_value,
                                           guint         n_param_values,
                                           const GValue *param_values,
                                           gpointer      invocation_hint,
                                           gpointer      marshal_data);

/* VOID:OBJECT,OBJECT (src/ui/gui/marshaller-list:12) */
extern void psppire_marshal_VOID__OBJECT_OBJECT (GClosure     *closure,
                                                 GValue       *return_value,
                                                 guint         n_param_values,
                                                 const GValue *param_values,
                                                 gpointer      invocation_hint,
                                                 gpointer      marshal_data);

/* VOID:POINTER,INT,INT (src/ui/gui/marshaller-list:13) */
extern void psppire_marshal_VOID__POINTER_INT_INT (GClosure     *closure,
                                                   GValue       *return_value,
                                                   guint         n_param_values,
                                                   const GValue *param_values,
                                                   gpointer      invocation_hint,
                                                   gpointer      marshal_data);

/* VOID:INT,UINT,POINTER (src/ui/gui/marshaller-list:14) */
extern void psppire_marshal_VOID__INT_UINT_POINTER (GClosure     *closure,
                                                    GValue       *return_value,
                                                    guint         n_param_values,
                                                    const GValue *param_values,
                                                    gpointer      invocation_hint,
                                                    gpointer      marshal_data);

G_END_DECLS

#endif /* __psppire_marshal_MARSHAL_H__ */

