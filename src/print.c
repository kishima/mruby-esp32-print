#include <mruby.h>
#include <mruby/string.h>
#include <stdio.h>

static mrb_value
mrb_printstr(mrb_state *mrb, mrb_value self)
{
  mrb_value str = mrb_get_arg1(mrb);
  
  printf("%.*s", (int)RSTRING_LEN(str), RSTRING_PTR(str));
  fflush(stdout);
  
  return str;
}

void
mrb_mruby_esp32_print_gem_init(mrb_state *mrb)
{
  struct RClass *krn = mrb->kernel_module;
  mrb_define_method(mrb, krn, "__printstr__", mrb_printstr, MRB_ARGS_REQ(1));
}

void
mrb_mruby_esp32_print_gem_final(mrb_state *mrb)
{
}
