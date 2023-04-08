#include "tst.h"

START_TEST(test) {
  char example[256] = {"-(-(-((sin(cos(48)^(2)))/(tan(2)^(2)))+3*(-6)))"};
  double res = str_unparser(str_parser(example));
  ck_assert_ldouble_eq_tol(-18.0834475532, res, 1e-7);

  char example1[256] = {"-100 / (8 + 2 * 7) * 0.5 ^ 2 + 8 - 6"};
  res = str_unparser(str_parser(example1));
  ck_assert_ldouble_eq_tol(0.86363636363, res, 1e-7);

  char example2[256] = {"2mod((sin(cos(48)^(2)))/(tan(2)^2))"};
  res = str_unparser(str_parser(example2));
  ck_assert_ldouble_eq_tol(0.0807062756, res, 1e-7);

  char example3[256] = {"((sin(95)+cos(96))^(2))/(log(sqrt(tan(1))))"};
  res = str_unparser(str_parser(example3));
  ck_assert_ldouble_eq_tol(2.6282352071, res, 1e-7);

  char example4[256] = {"sqrt((sin(cos(48)^2))/tan(2)^2)"};
  res = str_unparser(str_parser(example4));
  ck_assert_ldouble_eq_tol(0.28887290152, res, 1e-7);

  char example5[256] = {"(5-10)*777+(25-sin(10))"};
  res = str_unparser(str_parser(example5));
  ck_assert_ldouble_eq_tol(-3859.45597889, res, 1e-7);

  char example6[256] = {"-(100*(-1))+0.000001-0.00001"};
  res = str_unparser(str_parser(example6));
  ck_assert_ldouble_eq_tol(99.999991, res, 1e-7);

  char example7[256] = {"atan(acos(asin(sin(cos(tan(log(5)))))))"};
  res = str_unparser(str_parser(example7));
  ck_assert_ldouble_eq_tol(0.69897000433, res, 1e-7);

  char example8[256] = {"-ln(444^111)"};
  res = str_unparser(str_parser(example8));
  ck_assert_ldouble_eq_tol(-676.63652643, res, 1e-7);

  char example9[256] = {"77777777+7777*7777/2000000"};
  res = str_unparser(str_parser(example9));
  ck_assert_ldouble_eq_tol(77777807.240865, res, 1e-6);

  char example10[256] = {"-(100^(-100)+tan(2)*(-5))"};
  res = str_unparser(str_parser(example10));
  ck_assert_ldouble_eq_tol(-10.9251993163, res, 1e-7);

  char example11[256] = {"-(cos(555)*asin(0.5))-777.098765*sqrt(256)"};
  res = str_unparser(str_parser(example11));
  ck_assert_ldouble_eq_tol(-12433.3251353, res, 1e-7);

  char example12[256] = {"(1/1/1/(-(sin(-(cos(-1/(-ln(log(3)))))))))"};
  res = str_unparser(str_parser(example12));
  ck_assert_ldouble_eq_tol(4.63078860872, res, 1e-7);

  char example13[256] = {"cos(-1/(-ln(log(3))))"};
  res = str_unparser(str_parser(example13));
  ck_assert_ldouble_eq_tol(0.21766052492, res, 1e-7);

  char example14[256] = {"-(6544+765)-4+3/(432)*3-(-3)+(cos(3))"};
  res = str_unparser(str_parser(example14));
  ck_assert_ldouble_eq_tol(-7310.96915916, res, 1e-7);

  char example15[256] = {"-cos(5)"};
  res = str_unparser(str_parser(example15));
  ck_assert_ldouble_eq_tol(-0.28366218546, res, 1e-7);

  char example16[256] = {"-sin(-cos(5))"};
  res = str_unparser(str_parser(example16));
  ck_assert_ldouble_eq_tol(0.27987335076, res, 1e-7);

  char example17[256] = {"2mod2*2"};
  res = str_unparser(str_parser(example17));
  ck_assert_ldouble_eq_tol(0, res, 1e-7);

  char example18[256] = {"2^3^2"};
  res = str_unparser(str_parser(example18));
  ck_assert_ldouble_eq_tol(512, res, 1e-7);

  char example19[256] = {"coz(siz(sqrz(taz(moz(ataz(asiz(acoz(2))))))))"};
  res = str_unparser(str_parser(example19));
  ck_assert_ldouble_eq_tol(0, res, 1e-7);

  char example20[256] = {"2"};
  res = IsOkDouble(example20);
  ck_assert_ldouble_eq_tol(0, res, 1e-7);

  char example21[256] = {"2"};
  char *result = x_case(example21, 3);
  ck_assert_str_eq(example21, result);
}

Suite *tests() {
  Suite *s = suite_create("TEST");
  TCase *tc = tcase_create("all test");
  tcase_add_test(tc, test);
  suite_add_tcase(s, tc);
  return s;
}
