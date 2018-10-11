/*
** mrb_pocpoc.c - PocPoc class
**
** Copyright (c) Uchio Kondo 2018
**
** See Copyright Notice in LICENSE
*/

#include "mruby.h"
#include "mruby/data.h"
#include "mrb_pocpoc.h"

#define DONE mrb_gc_arena_restore(mrb, 0);

typedef struct {
  char *str;
  int len;
} mrb_pocpoc_data;

static const struct mrb_data_type mrb_pocpoc_data_type = {
  "mrb_pocpoc_data", mrb_free,
};

static mrb_value mrb_pocpoc_init(mrb_state *mrb, mrb_value self)
{
  mrb_pocpoc_data *data;
  char *str;
  int len;

  data = (mrb_pocpoc_data *)DATA_PTR(self);
  if (data) {
    mrb_free(mrb, data);
  }
  DATA_TYPE(self) = &mrb_pocpoc_data_type;
  DATA_PTR(self) = NULL;

  mrb_get_args(mrb, "s", &str, &len);
  data = (mrb_pocpoc_data *)mrb_malloc(mrb, sizeof(mrb_pocpoc_data));
  data->str = str;
  data->len = len;
  DATA_PTR(self) = data;

  return self;
}

static mrb_value mrb_pocpoc_hello(mrb_state *mrb, mrb_value self)
{
  mrb_pocpoc_data *data = DATA_PTR(self);

  return mrb_str_new(mrb, data->str, data->len);
}

static mrb_value mrb_pocpoc_hi(mrb_state *mrb, mrb_value self)
{
  return mrb_str_new_cstr(mrb, "hi!!");
}

void mrb_mruby_poc_1_gem_init(mrb_state *mrb)
{
  struct RClass *pocpoc;
  pocpoc = mrb_define_class(mrb, "PocPoc", mrb->object_class);
  mrb_define_method(mrb, pocpoc, "initialize", mrb_pocpoc_init, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, pocpoc, "hello", mrb_pocpoc_hello, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, pocpoc, "hi", mrb_pocpoc_hi, MRB_ARGS_NONE());
  DONE;
}

void mrb_mruby_poc_1_gem_final(mrb_state *mrb)
{
}

