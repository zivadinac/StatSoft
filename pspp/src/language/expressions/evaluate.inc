/* src/language/expressions/evaluate.inc
   Generated from ./src/language/expressions/operations.def by generate.pl.  
   Do not modify! */

case OP_ABS_n:
  {
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_ABS_n (arg_x);
  }
  break;

case OP_ACOS_n:
  {
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !(arg_x >= -1 && arg_x <= 1);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_ACOS_n (arg_x);
  }
  break;

case OP_ANY_nn:
  {
    size_t arg_n = op++->integer;
    double *arg_a = ns -= arg_n;
    double arg_x = *--ns;
    bool force_sysmis = !(arg_x != SYSMIS);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_ANY_nn (arg_x, arg_a, arg_n);
  }
  break;

case OP_ANY_ss:
  {
    size_t arg_n = op++->integer;
    struct substring *arg_a = ss -= arg_n;
    struct substring arg_x = *--ss;
    *ns++ = eval_OP_ANY_ss (arg_x, arg_a, arg_n);
  }
  break;

case OP_ARCOS_n:
  {
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !(arg_x >= -1 && arg_x <= 1);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_ARCOS_n (arg_x);
  }
  break;

case OP_ARSIN_n:
  {
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !(arg_x >= -1 && arg_x <= 1);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_ARSIN_n (arg_x);
  }
  break;

case OP_ARTAN_n:
  {
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_ARTAN_n (arg_x);
  }
  break;

case OP_ASIN_n:
  {
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !(arg_x >= -1 && arg_x <= 1);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_ASIN_n (arg_x);
  }
  break;

case OP_ATAN_n:
  {
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_ATAN_n (arg_x);
  }
  break;

case OP_CDF_BERNOULLI_nn:
  {
    double arg_p = *--ns;
    double arg_k = *--ns;
    bool force_sysmis = !is_valid (arg_k) || !is_valid (arg_p) || !(arg_k == 0 || arg_k == 1) || !(arg_p >= 0 && arg_p <= 1);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_CDF_BERNOULLI_nn (arg_k, arg_p);
  }
  break;

case OP_CDF_BETA_nnn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_x >= 0 && arg_x <= 1) || !(arg_a > 0) || !(arg_b > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_CDF_BETA_nnn (arg_x, arg_a, arg_b);
  }
  break;

case OP_CDF_BINOM_nnn:
  {
    double arg_p = *--ns;
    double arg_n = *--ns;
    double arg_k = *--ns;
    bool force_sysmis = !is_valid (arg_k) || !is_valid (arg_n) || !is_valid (arg_p) || !(arg_n > 0 && arg_n == floor (arg_n)) || !(arg_p >= 0 && arg_p <= 1);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_CDF_BINOM_nnn (arg_k, arg_n, arg_p);
  }
  break;

case OP_CDF_BVNOR_nnn:
  {
    double arg_r = *--ns;
    double arg_x1 = *--ns;
    double arg_x0 = *--ns;
    bool force_sysmis = !is_valid (arg_x0) || !is_valid (arg_x1) || !is_valid (arg_r) || !(arg_r >= -1 && arg_r <= 1);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_CDF_BVNOR_nnn (arg_x0, arg_x1, arg_r);
  }
  break;

case OP_CDF_CAUCHY_nnn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_b > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_CDF_CAUCHY_nnn (arg_x, arg_a, arg_b);
  }
  break;

case OP_CDF_CHISQ_nn:
  {
    double arg_df = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_df) || !(arg_x >= 0) || !(arg_df > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_CDF_CHISQ_nn (arg_x, arg_df);
  }
  break;

case OP_CDF_EXP_nn:
  {
    double arg_a = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !(arg_x >= 0) || !(arg_a > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_CDF_EXP_nn (arg_x, arg_a);
  }
  break;

case OP_CDF_F_nnn:
  {
    double arg_df2 = *--ns;
    double arg_df1 = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_df1) || !is_valid (arg_df2) || !(arg_x >= 0) || !(arg_df1 > 0) || !(arg_df2 > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_CDF_F_nnn (arg_x, arg_df1, arg_df2);
  }
  break;

case OP_CDF_GAMMA_nnn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_x >= 0) || !(arg_a > 0) || !(arg_b > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_CDF_GAMMA_nnn (arg_x, arg_a, arg_b);
  }
  break;

case OP_CDF_GEOM_nn:
  {
    double arg_p = *--ns;
    double arg_k = *--ns;
    bool force_sysmis = !is_valid (arg_k) || !is_valid (arg_p) || !(arg_k >= 1 && arg_k == floor (arg_k)) || !(arg_p >= 0 && arg_p <= 1);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_CDF_GEOM_nn (arg_k, arg_p);
  }
  break;

case OP_CDF_HALFNRM_nnn:
  NOT_REACHED ();

case OP_CDF_HYPER_nnnn:
  {
    double arg_c = *--ns;
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_k = *--ns;
    bool force_sysmis = !is_valid (arg_k) || !is_valid (arg_a) || !is_valid (arg_b) || !is_valid (arg_c) || !(arg_k >= 0 && arg_k == floor (arg_k) && arg_k <= arg_c) || !(arg_a > 0 && arg_a == floor (arg_a)) || !(arg_b > 0 && arg_b == floor (arg_b) && arg_b <= arg_a) || !(arg_c > 0 && arg_c == floor (arg_c) && arg_c <= arg_a);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_CDF_HYPER_nnnn (arg_k, arg_a, arg_b, arg_c);
  }
  break;

case OP_CDF_IGAUSS_nnn:
  NOT_REACHED ();

case OP_CDF_LAPLACE_nnn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_b > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_CDF_LAPLACE_nnn (arg_x, arg_a, arg_b);
  }
  break;

case OP_CDF_LNORMAL_nnn:
  {
    double arg_s = *--ns;
    double arg_m = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_m) || !is_valid (arg_s) || !(arg_x >= 0) || !(arg_m > 0) || !(arg_s > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_CDF_LNORMAL_nnn (arg_x, arg_m, arg_s);
  }
  break;

case OP_CDF_LOGISTIC_nnn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_b > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_CDF_LOGISTIC_nnn (arg_x, arg_a, arg_b);
  }
  break;

case OP_CDF_NEGBIN_nnn:
  {
    double arg_p = *--ns;
    double arg_n = *--ns;
    double arg_k = *--ns;
    bool force_sysmis = !is_valid (arg_k) || !is_valid (arg_n) || !is_valid (arg_p) || !(arg_k >= 1) || !(arg_n == floor (arg_n)) || !(arg_p > 0 && arg_p <= 1);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_CDF_NEGBIN_nnn (arg_k, arg_n, arg_p);
  }
  break;

case OP_CDF_NORMAL_nnn:
  {
    double arg_s = *--ns;
    double arg_u = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_u) || !is_valid (arg_s) || !(arg_s > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_CDF_NORMAL_nnn (arg_x, arg_u, arg_s);
  }
  break;

case OP_CDF_PARETO_nnn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_x >= arg_a) || !(arg_a > 0) || !(arg_b > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_CDF_PARETO_nnn (arg_x, arg_a, arg_b);
  }
  break;

case OP_CDF_POISSON_nn:
  {
    double arg_mu = *--ns;
    double arg_k = *--ns;
    bool force_sysmis = !is_valid (arg_k) || !is_valid (arg_mu) || !(arg_k >= 0 && arg_k == floor (arg_k)) || !(arg_mu > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_CDF_POISSON_nn (arg_k, arg_mu);
  }
  break;

case OP_CDF_RAYLEIGH_nn:
  {
    double arg_sigma = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_sigma) || !(arg_sigma > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_CDF_RAYLEIGH_nn (arg_x, arg_sigma);
  }
  break;

case OP_CDF_SMOD_nnn:
  NOT_REACHED ();

case OP_CDF_SRANGE_nnn:
  NOT_REACHED ();

case OP_CDF_T_nn:
  {
    double arg_df = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_df) || !(arg_df > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_CDF_T_nn (arg_x, arg_df);
  }
  break;

case OP_CDF_T1G_nnn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_CDF_T1G_nnn (arg_x, arg_a, arg_b);
  }
  break;

case OP_CDF_T2G_nnn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_CDF_T2G_nnn (arg_x, arg_a, arg_b);
  }
  break;

case OP_CDF_UNIFORM_nnn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_x <= arg_b) || !(arg_a <= arg_x);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_CDF_UNIFORM_nnn (arg_x, arg_a, arg_b);
  }
  break;

case OP_CDF_WEIBULL_nnn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_x >= 0) || !(arg_a > 0) || !(arg_b > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_CDF_WEIBULL_nnn (arg_x, arg_a, arg_b);
  }
  break;

case OP_CDFNORM_n:
  {
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_CDFNORM_n (arg_x);
  }
  break;

case OP_CFVAR_n:
  {
    size_t arg_n = op++->integer;
    double *arg_a = ns -= arg_n;
    bool force_sysmis = count_valid (arg_a, arg_n) < op++->integer;
    *ns++ = force_sysmis ? SYSMIS : eval_OP_CFVAR_n (arg_a, arg_n);
  }
  break;

case OP_CONCAT_s:
  {
    size_t arg_n = op++->integer;
    struct substring *arg_a = ss -= arg_n;
    *ss++ = eval_OP_CONCAT_s (arg_a, arg_n, e);
  }
  break;

case OP_COS_n:
  {
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_COS_n (arg_x);
  }
  break;

case OP_CTIME_DAYS_n:
  {
    double arg_time = *--ns;
    bool force_sysmis = !is_valid (arg_time);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_CTIME_DAYS_n (arg_time);
  }
  break;

case OP_CTIME_HOURS_n:
  {
    double arg_time = *--ns;
    bool force_sysmis = !is_valid (arg_time);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_CTIME_HOURS_n (arg_time);
  }
  break;

case OP_CTIME_MINUTES_n:
  {
    double arg_time = *--ns;
    bool force_sysmis = !is_valid (arg_time);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_CTIME_MINUTES_n (arg_time);
  }
  break;

case OP_CTIME_SECONDS_n:
  {
    double arg_time = *--ns;
    bool force_sysmis = !is_valid (arg_time);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_CTIME_SECONDS_n (arg_time);
  }
  break;

case OP_DATE_DMY_nnn:
  {
    double arg_y = *--ns;
    double arg_m = *--ns;
    double arg_d = *--ns;
    bool force_sysmis = !is_valid (arg_d) || !is_valid (arg_m) || !is_valid (arg_y);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_DATE_DMY_nnn (arg_d, arg_m, arg_y);
  }
  break;

case OP_DATE_MDY_nnn:
  {
    double arg_y = *--ns;
    double arg_d = *--ns;
    double arg_m = *--ns;
    bool force_sysmis = !is_valid (arg_m) || !is_valid (arg_d) || !is_valid (arg_y);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_DATE_MDY_nnn (arg_m, arg_d, arg_y);
  }
  break;

case OP_DATE_MOYR_nn:
  {
    double arg_y = *--ns;
    double arg_m = *--ns;
    bool force_sysmis = !is_valid (arg_m) || !is_valid (arg_y);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_DATE_MOYR_nn (arg_m, arg_y);
  }
  break;

case OP_DATE_QYR_nn:
  {
    double arg_y = *--ns;
    double arg_q = *--ns;
    bool force_sysmis = !is_valid (arg_q) || !is_valid (arg_y);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_DATE_QYR_nn (arg_q, arg_y);
  }
  break;

case OP_DATE_WKYR_nn:
  {
    double arg_y = *--ns;
    double arg_w = *--ns;
    bool force_sysmis = !is_valid (arg_w) || !is_valid (arg_y);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_DATE_WKYR_nn (arg_w, arg_y);
  }
  break;

case OP_DATE_YRDAY_nn:
  {
    double arg_yday = *--ns;
    double arg_y = *--ns;
    bool force_sysmis = !is_valid (arg_y) || !is_valid (arg_yday);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_DATE_YRDAY_nn (arg_y, arg_yday);
  }
  break;

case OP_DATEDIFF_nns:
  {
    struct substring arg_unit = *--ss;
    double arg_date1 = *--ns;
    double arg_date2 = *--ns;
    bool force_sysmis = !is_valid (arg_date2) || !is_valid (arg_date1) || !(arg_date2 >= DAY_S) || !(arg_date1 >= DAY_S);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_DATEDIFF_nns (arg_date2, arg_date1, arg_unit);
  }
  break;

case OP_DATESUM_nns:
  {
    struct substring arg_unit = *--ss;
    double arg_quantity = *--ns;
    double arg_date = *--ns;
    bool force_sysmis = !is_valid (arg_date) || !is_valid (arg_quantity);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_DATESUM_nns (arg_date, arg_quantity, arg_unit);
  }
  break;

case OP_DATESUM_nnss:
  {
    struct substring arg_method = *--ss;
    struct substring arg_unit = *--ss;
    double arg_quantity = *--ns;
    double arg_date = *--ns;
    bool force_sysmis = !is_valid (arg_date) || !is_valid (arg_quantity);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_DATESUM_nnss (arg_date, arg_quantity, arg_unit, arg_method);
  }
  break;

case OP_EXP_n:
  {
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_EXP_n (arg_x);
  }
  break;

case OP_IDF_BETA_nnn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_P = *--ns;
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_P >= 0 && arg_P <= 1) || !(arg_a > 0) || !(arg_b > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_IDF_BETA_nnn (arg_P, arg_a, arg_b);
  }
  break;

case OP_IDF_CAUCHY_nnn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_P = *--ns;
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_P > 0 && arg_P < 1) || !(arg_b > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_IDF_CAUCHY_nnn (arg_P, arg_a, arg_b);
  }
  break;

case OP_IDF_CHISQ_nn:
  {
    double arg_df = *--ns;
    double arg_P = *--ns;
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_df) || !(arg_P >= 0 && arg_P < 1) || !(arg_df > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_IDF_CHISQ_nn (arg_P, arg_df);
  }
  break;

case OP_IDF_EXP_nn:
  {
    double arg_a = *--ns;
    double arg_P = *--ns;
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_a) || !(arg_P >= 0 && arg_P < 1) || !(arg_a > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_IDF_EXP_nn (arg_P, arg_a);
  }
  break;

case OP_IDF_F_nnn:
  {
    double arg_df2 = *--ns;
    double arg_df1 = *--ns;
    double arg_P = *--ns;
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_df1) || !is_valid (arg_df2) || !(arg_P >= 0 && arg_P < 1) || !(arg_df1 > 0) || !(arg_df2 > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_IDF_F_nnn (arg_P, arg_df1, arg_df2);
  }
  break;

case OP_IDF_GAMMA_nnn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_P = *--ns;
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_P >= 0 && arg_P <= 1) || !(arg_a > 0) || !(arg_b > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_IDF_GAMMA_nnn (arg_P, arg_a, arg_b);
  }
  break;

case OP_IDF_HALFNRM_nnn:
  NOT_REACHED ();

case OP_IDF_IGAUSS_nnn:
  NOT_REACHED ();

case OP_IDF_LAPLACE_nnn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_P = *--ns;
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_P > 0 && arg_P < 1) || !(arg_b > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_IDF_LAPLACE_nnn (arg_P, arg_a, arg_b);
  }
  break;

case OP_IDF_LNORMAL_nnn:
  {
    double arg_s = *--ns;
    double arg_m = *--ns;
    double arg_P = *--ns;
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_m) || !is_valid (arg_s) || !(arg_P >= 0 && arg_P < 1) || !(arg_m > 0) || !(arg_s > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_IDF_LNORMAL_nnn (arg_P, arg_m, arg_s);
  }
  break;

case OP_IDF_LOGISTIC_nnn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_P = *--ns;
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_P > 0 && arg_P < 1) || !(arg_b > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_IDF_LOGISTIC_nnn (arg_P, arg_a, arg_b);
  }
  break;

case OP_IDF_NORMAL_nnn:
  {
    double arg_s = *--ns;
    double arg_u = *--ns;
    double arg_P = *--ns;
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_u) || !is_valid (arg_s) || !(arg_P > 0 && arg_P < 1) || !(arg_s > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_IDF_NORMAL_nnn (arg_P, arg_u, arg_s);
  }
  break;

case OP_IDF_PARETO_nnn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_P = *--ns;
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_P >= 0 && arg_P < 1) || !(arg_a > 0) || !(arg_b > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_IDF_PARETO_nnn (arg_P, arg_a, arg_b);
  }
  break;

case OP_IDF_RAYLEIGH_nn:
  {
    double arg_sigma = *--ns;
    double arg_P = *--ns;
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_sigma) || !(arg_P >= 0 && arg_P <= 1) || !(arg_sigma > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_IDF_RAYLEIGH_nn (arg_P, arg_sigma);
  }
  break;

case OP_IDF_SMOD_nnn:
  NOT_REACHED ();

case OP_IDF_SRANGE_nnn:
  NOT_REACHED ();

case OP_IDF_T_nn:
  {
    double arg_df = *--ns;
    double arg_P = *--ns;
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_df) || !(arg_P > 0 && arg_P < 1) || !(arg_df > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_IDF_T_nn (arg_P, arg_df);
  }
  break;

case OP_IDF_T1G_nnn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_P = *--ns;
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_P >= 0 && arg_P <= 1);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_IDF_T1G_nnn (arg_P, arg_a, arg_b);
  }
  break;

case OP_IDF_T2G_nnn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_P = *--ns;
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_P >= 0 && arg_P <= 1);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_IDF_T2G_nnn (arg_P, arg_a, arg_b);
  }
  break;

case OP_IDF_UNIFORM_nnn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_P = *--ns;
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_P >= 0 && arg_P <= 1) || !(arg_a <= arg_b);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_IDF_UNIFORM_nnn (arg_P, arg_a, arg_b);
  }
  break;

case OP_IDF_WEIBULL_nnn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_P = *--ns;
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_P >= 0 && arg_P < 1) || !(arg_a > 0) || !(arg_b > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_IDF_WEIBULL_nnn (arg_P, arg_a, arg_b);
  }
  break;

case OP_INDEX_ss:
  {
    struct substring arg_needle = *--ss;
    struct substring arg_haystack = *--ss;
    *ns++ = eval_OP_INDEX_ss (arg_haystack, arg_needle);
  }
  break;

case OP_INDEX_ssn:
  {
    double arg_needle_len_d = *--ns;
    struct substring arg_needles = *--ss;
    struct substring arg_haystack = *--ss;
    bool force_sysmis = !is_valid (arg_needle_len_d);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_INDEX_ssn (arg_haystack, arg_needles, arg_needle_len_d);
  }
  break;

case OP_LAG_Vn:
  {
    const struct variable *arg_v = op++->variable;
    *ns++ = eval_OP_LAG_Vn (arg_v, ds);
  }
  break;

case OP_LAG_Vnn:
  {
    const struct variable *arg_v = op++->variable;
    int arg_n_before = op++->integer;
    *ns++ = eval_OP_LAG_Vnn (arg_v, arg_n_before, ds);
  }
  break;

case OP_LAG_Vs:
  {
    const struct variable *arg_v = op++->variable;
    *ss++ = eval_OP_LAG_Vs (arg_v, e, ds);
  }
  break;

case OP_LAG_Vsn:
  {
    const struct variable *arg_v = op++->variable;
    int arg_n_before = op++->integer;
    *ss++ = eval_OP_LAG_Vsn (arg_v, arg_n_before, e, ds);
  }
  break;

case OP_LENGTH_s:
  {
    struct substring arg_s = *--ss;
    *ns++ = eval_OP_LENGTH_s (arg_s);
  }
  break;

case OP_LG10_n:
  {
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_LG10_n (arg_x);
  }
  break;

case OP_LN_n:
  {
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_LN_n (arg_x);
  }
  break;

case OP_LNGAMMA_n:
  {
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !(arg_x >= 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_LNGAMMA_n (arg_x);
  }
  break;

case OP_LOWER_s:
  {
    struct substring arg_s = *--ss;
    *ss++ = eval_OP_LOWER_s (arg_s);
  }
  break;

case OP_LPAD_sn:
  {
    double arg_n = *--ns;
    struct substring arg_s = *--ss;
    *ss++ = eval_OP_LPAD_sn (arg_s, arg_n, e);
  }
  break;

case OP_LPAD_sns:
  {
    struct substring arg_c = *--ss;
    double arg_n = *--ns;
    struct substring arg_s = *--ss;
    *ss++ = eval_OP_LPAD_sns (arg_s, arg_n, arg_c, e);
  }
  break;

case OP_LTRIM_s:
  {
    struct substring arg_s = *--ss;
    *ss++ = eval_OP_LTRIM_s (arg_s);
  }
  break;

case OP_LTRIM_ss:
  {
    struct substring arg_c = *--ss;
    struct substring arg_s = *--ss;
    *ss++ = eval_OP_LTRIM_ss (arg_s, arg_c);
  }
  break;

case OP_MAX_n:
  {
    size_t arg_n = op++->integer;
    double *arg_a = ns -= arg_n;
    bool force_sysmis = count_valid (arg_a, arg_n) < op++->integer;
    *ns++ = force_sysmis ? SYSMIS : eval_OP_MAX_n (arg_a, arg_n);
  }
  break;

case OP_MAX_s:
  {
    size_t arg_n = op++->integer;
    struct substring *arg_a = ss -= arg_n;
    *ss++ = eval_OP_MAX_s (arg_a, arg_n);
  }
  break;

case OP_MBLEN_BYTE_sn:
  {
    double arg_idx = *--ns;
    struct substring arg_s = *--ss;
    bool force_sysmis = !is_valid (arg_idx);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_MBLEN_BYTE_sn (arg_s, arg_idx);
  }
  break;

case OP_MEAN_n:
  {
    size_t arg_n = op++->integer;
    double *arg_a = ns -= arg_n;
    bool force_sysmis = count_valid (arg_a, arg_n) < op++->integer;
    *ns++ = force_sysmis ? SYSMIS : eval_OP_MEAN_n (arg_a, arg_n);
  }
  break;

case OP_MEDIAN_n:
  {
    size_t arg_n = op++->integer;
    double *arg_a = ns -= arg_n;
    bool force_sysmis = count_valid (arg_a, arg_n) < op++->integer;
    *ns++ = force_sysmis ? SYSMIS : eval_OP_MEDIAN_n (arg_a, arg_n);
  }
  break;

case OP_MIN_n:
  {
    size_t arg_n = op++->integer;
    double *arg_a = ns -= arg_n;
    bool force_sysmis = count_valid (arg_a, arg_n) < op++->integer;
    *ns++ = force_sysmis ? SYSMIS : eval_OP_MIN_n (arg_a, arg_n);
  }
  break;

case OP_MIN_s:
  {
    size_t arg_n = op++->integer;
    struct substring *arg_a = ss -= arg_n;
    *ss++ = eval_OP_MIN_s (arg_a, arg_n);
  }
  break;

case OP_MISSING_n:
  {
    double arg_x = *--ns;
    *ns++ = eval_OP_MISSING_n (arg_x);
  }
  break;

case OP_MOD_nn:
  {
    double arg_d = *--ns;
    double arg_n = *--ns;
    *ns++ = eval_OP_MOD_nn (arg_n, arg_d);
  }
  break;

case OP_MOD10_n:
  {
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_MOD10_n (arg_x);
  }
  break;

case OP_NCDF_BETA_nnnn:
  {
    double arg_lambda = *--ns;
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !is_valid (arg_lambda) || !(arg_x >= 0) || !(arg_a > 0) || !(arg_b > 0) || !(arg_lambda > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_NCDF_BETA_nnnn (arg_x, arg_a, arg_b, arg_lambda);
  }
  break;

case OP_NCDF_CHISQ_nnn:
  NOT_REACHED ();

case OP_NCDF_F_nnnn:
  NOT_REACHED ();

case OP_NCDF_T_nnn:
  NOT_REACHED ();

case OP_NMISS_n:
  {
    size_t arg_n = op++->integer;
    double *arg_a = ns -= arg_n;
    *ns++ = eval_OP_NMISS_n (arg_a, arg_n);
  }
  break;

case OP_NORMAL_n:
  {
    double arg_s = *--ns;
    bool force_sysmis = !is_valid (arg_s) || !(arg_s > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_NORMAL_n (arg_s);
  }
  break;

case OP_NPDF_BETA_nnnn:
  {
    double arg_lambda = *--ns;
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !is_valid (arg_lambda) || !(arg_x >= 0) || !(arg_a > 0) || !(arg_b > 0) || !(arg_lambda > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_NPDF_BETA_nnnn (arg_x, arg_a, arg_b, arg_lambda);
  }
  break;

case OP_NPDF_CHISQ_nnn:
  NOT_REACHED ();

case OP_NPDF_F_nnnn:
  NOT_REACHED ();

case OP_NPDF_T_nnn:
  NOT_REACHED ();

case OP_NUMBER_sf:
  {
    struct substring arg_s = *--ss;
    const struct fmt_spec *arg_f = op++->format;
    *ns++ = eval_OP_NUMBER_sf (arg_s, arg_f);
  }
  break;

case OP_NVALID_n:
  {
    size_t arg_n = op++->integer;
    double *arg_a = ns -= arg_n;
    *ns++ = eval_OP_NVALID_n (arg_a, arg_n);
  }
  break;

case OP_PDF_BERNOULLI_nn:
  {
    double arg_p = *--ns;
    double arg_k = *--ns;
    bool force_sysmis = !is_valid (arg_k) || !is_valid (arg_p) || !(arg_k == 0 || arg_k == 1) || !(arg_p >= 0 && arg_p <= 1);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_PDF_BERNOULLI_nn (arg_k, arg_p);
  }
  break;

case OP_PDF_BETA_nnn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_x >= 0 && arg_x <= 1) || !(arg_a > 0) || !(arg_b > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_PDF_BETA_nnn (arg_x, arg_a, arg_b);
  }
  break;

case OP_PDF_BINOM_nnn:
  {
    double arg_p = *--ns;
    double arg_n = *--ns;
    double arg_k = *--ns;
    bool force_sysmis = !is_valid (arg_k) || !is_valid (arg_n) || !is_valid (arg_p) || !(arg_k >= 0 && arg_k == floor (arg_k) && arg_k <= arg_n) || !(arg_n > 0 && arg_n == floor (arg_n)) || !(arg_p >= 0 && arg_p <= 1);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_PDF_BINOM_nnn (arg_k, arg_n, arg_p);
  }
  break;

case OP_PDF_BVNOR_nnn:
  {
    double arg_r = *--ns;
    double arg_x1 = *--ns;
    double arg_x0 = *--ns;
    bool force_sysmis = !is_valid (arg_x0) || !is_valid (arg_x1) || !is_valid (arg_r) || !(arg_r >= -1 && arg_r <= 1);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_PDF_BVNOR_nnn (arg_x0, arg_x1, arg_r);
  }
  break;

case OP_PDF_CAUCHY_nnn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_b > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_PDF_CAUCHY_nnn (arg_x, arg_a, arg_b);
  }
  break;

case OP_PDF_CHISQ_nn:
  {
    double arg_df = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_df) || !(arg_x >= 0) || !(arg_df > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_PDF_CHISQ_nn (arg_x, arg_df);
  }
  break;

case OP_PDF_EXP_nn:
  {
    double arg_a = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !(arg_x >= 0) || !(arg_a > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_PDF_EXP_nn (arg_x, arg_a);
  }
  break;

case OP_PDF_F_nnn:
  {
    double arg_df2 = *--ns;
    double arg_df1 = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_df1) || !is_valid (arg_df2) || !(arg_x >= 0) || !(arg_df1 > 0) || !(arg_df2 > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_PDF_F_nnn (arg_x, arg_df1, arg_df2);
  }
  break;

case OP_PDF_GAMMA_nnn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_x >= 0) || !(arg_a > 0) || !(arg_b > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_PDF_GAMMA_nnn (arg_x, arg_a, arg_b);
  }
  break;

case OP_PDF_GEOM_nn:
  {
    double arg_p = *--ns;
    double arg_k = *--ns;
    bool force_sysmis = !is_valid (arg_k) || !is_valid (arg_p) || !(arg_k >= 1 && arg_k == floor (arg_k)) || !(arg_p >= 0 && arg_p <= 1);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_PDF_GEOM_nn (arg_k, arg_p);
  }
  break;

case OP_PDF_HALFNRM_nnn:
  NOT_REACHED ();

case OP_PDF_HYPER_nnnn:
  {
    double arg_c = *--ns;
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_k = *--ns;
    bool force_sysmis = !is_valid (arg_k) || !is_valid (arg_a) || !is_valid (arg_b) || !is_valid (arg_c) || !(arg_k >= 0 && arg_k == floor (arg_k) && arg_k <= arg_c) || !(arg_a > 0 && arg_a == floor (arg_a)) || !(arg_b > 0 && arg_b == floor (arg_b) && arg_b <= arg_a) || !(arg_c > 0 && arg_c == floor (arg_c) && arg_c <= arg_a);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_PDF_HYPER_nnnn (arg_k, arg_a, arg_b, arg_c);
  }
  break;

case OP_PDF_IGAUSS_nnn:
  NOT_REACHED ();

case OP_PDF_LANDAU_n:
  {
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_PDF_LANDAU_n (arg_x);
  }
  break;

case OP_PDF_LAPLACE_nnn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_b > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_PDF_LAPLACE_nnn (arg_x, arg_a, arg_b);
  }
  break;

case OP_PDF_LNORMAL_nnn:
  {
    double arg_s = *--ns;
    double arg_m = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_m) || !is_valid (arg_s) || !(arg_x >= 0) || !(arg_m > 0) || !(arg_s > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_PDF_LNORMAL_nnn (arg_x, arg_m, arg_s);
  }
  break;

case OP_PDF_LOG_nn:
  {
    double arg_p = *--ns;
    double arg_k = *--ns;
    bool force_sysmis = !is_valid (arg_k) || !is_valid (arg_p) || !(arg_k >= 1) || !(arg_p > 0 && arg_p <= 1);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_PDF_LOG_nn (arg_k, arg_p);
  }
  break;

case OP_PDF_LOGISTIC_nnn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_b > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_PDF_LOGISTIC_nnn (arg_x, arg_a, arg_b);
  }
  break;

case OP_PDF_NEGBIN_nnn:
  {
    double arg_p = *--ns;
    double arg_n = *--ns;
    double arg_k = *--ns;
    bool force_sysmis = !is_valid (arg_k) || !is_valid (arg_n) || !is_valid (arg_p) || !(arg_k >= 1) || !(arg_n == floor (arg_n)) || !(arg_p > 0 && arg_p <= 1);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_PDF_NEGBIN_nnn (arg_k, arg_n, arg_p);
  }
  break;

case OP_PDF_NORMAL_nnn:
  {
    double arg_s = *--ns;
    double arg_u = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_u) || !is_valid (arg_s) || !(arg_s > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_PDF_NORMAL_nnn (arg_x, arg_u, arg_s);
  }
  break;

case OP_PDF_NTAIL_nnn:
  {
    double arg_sigma = *--ns;
    double arg_a = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_sigma) || !(arg_a > 0) || !(arg_sigma > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_PDF_NTAIL_nnn (arg_x, arg_a, arg_sigma);
  }
  break;

case OP_PDF_PARETO_nnn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_x >= arg_a) || !(arg_a > 0) || !(arg_b > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_PDF_PARETO_nnn (arg_x, arg_a, arg_b);
  }
  break;

case OP_PDF_POISSON_nn:
  {
    double arg_mu = *--ns;
    double arg_k = *--ns;
    bool force_sysmis = !is_valid (arg_k) || !is_valid (arg_mu) || !(arg_k >= 0 && arg_k == floor (arg_k)) || !(arg_mu > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_PDF_POISSON_nn (arg_k, arg_mu);
  }
  break;

case OP_PDF_RAYLEIGH_nn:
  {
    double arg_sigma = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_sigma) || !(arg_sigma > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_PDF_RAYLEIGH_nn (arg_x, arg_sigma);
  }
  break;

case OP_PDF_RTAIL_nnn:
  {
    double arg_sigma = *--ns;
    double arg_a = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_sigma);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_PDF_RTAIL_nnn (arg_x, arg_a, arg_sigma);
  }
  break;

case OP_PDF_T_nn:
  {
    double arg_df = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_df) || !(arg_df > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_PDF_T_nn (arg_x, arg_df);
  }
  break;

case OP_PDF_T1G_nnn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_PDF_T1G_nnn (arg_x, arg_a, arg_b);
  }
  break;

case OP_PDF_T2G_nnn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_PDF_T2G_nnn (arg_x, arg_a, arg_b);
  }
  break;

case OP_PDF_UNIFORM_nnn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_x <= arg_b) || !(arg_a <= arg_x);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_PDF_UNIFORM_nnn (arg_x, arg_a, arg_b);
  }
  break;

case OP_PDF_WEIBULL_nnn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_x >= 0) || !(arg_a > 0) || !(arg_b > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_PDF_WEIBULL_nnn (arg_x, arg_a, arg_b);
  }
  break;

case OP_PDF_XPOWER_nnn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_a > 0) || !(arg_b >= 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_PDF_XPOWER_nnn (arg_x, arg_a, arg_b);
  }
  break;

case OP_PROBIT_n:
  {
    double arg_P = *--ns;
    bool force_sysmis = !is_valid (arg_P) || !(arg_P > 0 && arg_P < 1);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_PROBIT_n (arg_P);
  }
  break;

case OP_RANGE_nn:
  {
    size_t arg_n = op++->integer;
    double *arg_a = ns -= arg_n;
    double arg_x = *--ns;
    bool force_sysmis = !(arg_x != SYSMIS);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RANGE_nn (arg_x, arg_a, arg_n / 2);
  }
  break;

case OP_RANGE_ss:
  {
    size_t arg_n = op++->integer;
    struct substring *arg_a = ss -= arg_n;
    struct substring arg_x = *--ss;
    *ns++ = eval_OP_RANGE_ss (arg_x, arg_a, arg_n / 2);
  }
  break;

case OP_REPLACE_sss:
  {
    struct substring arg_replacement = *--ss;
    struct substring arg_needle = *--ss;
    struct substring arg_haystack = *--ss;
    *ss++ = eval_OP_REPLACE_sss (arg_haystack, arg_needle, arg_replacement, e);
  }
  break;

case OP_REPLACE_sssn:
  {
    double arg_n = *--ns;
    struct substring arg_replacement = *--ss;
    struct substring arg_needle = *--ss;
    struct substring arg_haystack = *--ss;
    *ss++ = eval_OP_REPLACE_sssn (arg_haystack, arg_needle, arg_replacement, arg_n, e);
  }
  break;

case OP_RINDEX_ss:
  {
    struct substring arg_needle = *--ss;
    struct substring arg_haystack = *--ss;
    *ns++ = eval_OP_RINDEX_ss (arg_haystack, arg_needle);
  }
  break;

case OP_RINDEX_ssn:
  {
    double arg_needle_len_d = *--ns;
    struct substring arg_needles = *--ss;
    struct substring arg_haystack = *--ss;
    bool force_sysmis = !is_valid (arg_needle_len_d);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RINDEX_ssn (arg_haystack, arg_needles, arg_needle_len_d);
  }
  break;

case OP_RND_n:
  {
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RND_n (arg_x);
  }
  break;

case OP_RND_nn:
  {
    double arg_mult = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_mult) || !(arg_mult != 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RND_nn (arg_x, arg_mult);
  }
  break;

case OP_RND_nnn:
  {
    double arg_fuzzbits = *--ns;
    double arg_mult = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_mult) || !is_valid (arg_fuzzbits) || !(arg_mult != 0) || !(arg_fuzzbits >= 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RND_nnn (arg_x, arg_mult, arg_fuzzbits);
  }
  break;

case OP_RPAD_sn:
  {
    double arg_n = *--ns;
    struct substring arg_s = *--ss;
    *ss++ = eval_OP_RPAD_sn (arg_s, arg_n, e);
  }
  break;

case OP_RPAD_sns:
  {
    struct substring arg_c = *--ss;
    double arg_n = *--ns;
    struct substring arg_s = *--ss;
    *ss++ = eval_OP_RPAD_sns (arg_s, arg_n, arg_c, e);
  }
  break;

case OP_RTRIM_s:
  {
    struct substring arg_s = *--ss;
    *ss++ = eval_OP_RTRIM_s (arg_s);
  }
  break;

case OP_RTRIM_ss:
  {
    struct substring arg_c = *--ss;
    struct substring arg_s = *--ss;
    *ss++ = eval_OP_RTRIM_ss (arg_s, arg_c);
  }
  break;

case OP_RV_BERNOULLI_n:
  {
    double arg_p = *--ns;
    bool force_sysmis = !is_valid (arg_p) || !(arg_p >= 0 && arg_p <= 1);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RV_BERNOULLI_n (arg_p);
  }
  break;

case OP_RV_BETA_nn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    bool force_sysmis = !is_valid (arg_a) || !is_valid (arg_b) || !(arg_a > 0) || !(arg_b > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RV_BETA_nn (arg_a, arg_b);
  }
  break;

case OP_RV_BINOM_nn:
  {
    double arg_n = *--ns;
    double arg_p = *--ns;
    bool force_sysmis = !is_valid (arg_p) || !is_valid (arg_n) || !(arg_p > 0 && arg_p == floor (arg_p)) || !(arg_n >= 0 && arg_n <= 1);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RV_BINOM_nn (arg_p, arg_n);
  }
  break;

case OP_RV_CAUCHY_nn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    bool force_sysmis = !is_valid (arg_a) || !is_valid (arg_b) || !(arg_b > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RV_CAUCHY_nn (arg_a, arg_b);
  }
  break;

case OP_RV_CHISQ_n:
  {
    double arg_df = *--ns;
    bool force_sysmis = !is_valid (arg_df) || !(arg_df > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RV_CHISQ_n (arg_df);
  }
  break;

case OP_RV_EXP_n:
  {
    double arg_a = *--ns;
    bool force_sysmis = !is_valid (arg_a) || !(arg_a > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RV_EXP_n (arg_a);
  }
  break;

case OP_RV_F_nn:
  {
    double arg_df2 = *--ns;
    double arg_df1 = *--ns;
    bool force_sysmis = !is_valid (arg_df1) || !is_valid (arg_df2) || !(arg_df1 > 0) || !(arg_df2 > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RV_F_nn (arg_df1, arg_df2);
  }
  break;

case OP_RV_GAMMA_nn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    bool force_sysmis = !is_valid (arg_a) || !is_valid (arg_b) || !(arg_a > 0) || !(arg_b > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RV_GAMMA_nn (arg_a, arg_b);
  }
  break;

case OP_RV_GEOM_n:
  {
    double arg_p = *--ns;
    bool force_sysmis = !is_valid (arg_p) || !(arg_p >= 0 && arg_p <= 1);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RV_GEOM_n (arg_p);
  }
  break;

case OP_RV_HALFNRM_nn:
  NOT_REACHED ();

case OP_RV_HYPER_nnn:
  {
    double arg_c = *--ns;
    double arg_b = *--ns;
    double arg_a = *--ns;
    bool force_sysmis = !is_valid (arg_a) || !is_valid (arg_b) || !is_valid (arg_c) || !(arg_a > 0 && arg_a == floor (arg_a)) || !(arg_b > 0 && arg_b == floor (arg_b) && arg_b <= arg_a) || !(arg_c > 0 && arg_c == floor (arg_c) && arg_c <= arg_a);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RV_HYPER_nnn (arg_a, arg_b, arg_c);
  }
  break;

case OP_RV_IGAUSS_nn:
  NOT_REACHED ();

case OP_RV_LANDAU_:
  *ns++ = eval_OP_RV_LANDAU_ ();
  break;

case OP_RV_LAPLACE_nn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    bool force_sysmis = !is_valid (arg_a) || !is_valid (arg_b) || !(arg_b > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RV_LAPLACE_nn (arg_a, arg_b);
  }
  break;

case OP_RV_LEVY_nn:
  {
    double arg_alpha = *--ns;
    double arg_c = *--ns;
    bool force_sysmis = !is_valid (arg_c) || !is_valid (arg_alpha) || !(arg_alpha > 0 && arg_alpha <= 2);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RV_LEVY_nn (arg_c, arg_alpha);
  }
  break;

case OP_RV_LNORMAL_nn:
  {
    double arg_s = *--ns;
    double arg_m = *--ns;
    bool force_sysmis = !is_valid (arg_m) || !is_valid (arg_s) || !(arg_m > 0) || !(arg_s > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RV_LNORMAL_nn (arg_m, arg_s);
  }
  break;

case OP_RV_LOG_n:
  {
    double arg_p = *--ns;
    bool force_sysmis = !is_valid (arg_p) || !(arg_p > 0 && arg_p <= 1);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RV_LOG_n (arg_p);
  }
  break;

case OP_RV_LOGISTIC_nn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    bool force_sysmis = !is_valid (arg_a) || !is_valid (arg_b) || !(arg_b > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RV_LOGISTIC_nn (arg_a, arg_b);
  }
  break;

case OP_RV_LVSKEW_nnn:
  {
    double arg_beta = *--ns;
    double arg_alpha = *--ns;
    double arg_c = *--ns;
    bool force_sysmis = !is_valid (arg_c) || !is_valid (arg_alpha) || !is_valid (arg_beta) || !(arg_alpha > 0 && arg_alpha <= 2) || !(arg_beta >= -1 && arg_beta <= 1);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RV_LVSKEW_nnn (arg_c, arg_alpha, arg_beta);
  }
  break;

case OP_RV_NEGBIN_nn:
  {
    double arg_p = *--ns;
    double arg_n = *--ns;
    bool force_sysmis = !is_valid (arg_n) || !is_valid (arg_p) || !(arg_n == floor (arg_n)) || !(arg_p > 0 && arg_p <= 1);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RV_NEGBIN_nn (arg_n, arg_p);
  }
  break;

case OP_RV_NORMAL_nn:
  {
    double arg_s = *--ns;
    double arg_u = *--ns;
    bool force_sysmis = !is_valid (arg_u) || !is_valid (arg_s) || !(arg_s > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RV_NORMAL_nn (arg_u, arg_s);
  }
  break;

case OP_RV_NTAIL_nn:
  {
    double arg_sigma = *--ns;
    double arg_a = *--ns;
    bool force_sysmis = !is_valid (arg_a) || !is_valid (arg_sigma) || !(arg_a > 0) || !(arg_sigma > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RV_NTAIL_nn (arg_a, arg_sigma);
  }
  break;

case OP_RV_PARETO_nn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    bool force_sysmis = !is_valid (arg_a) || !is_valid (arg_b) || !(arg_a > 0) || !(arg_b > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RV_PARETO_nn (arg_a, arg_b);
  }
  break;

case OP_RV_POISSON_n:
  {
    double arg_mu = *--ns;
    bool force_sysmis = !is_valid (arg_mu) || !(arg_mu > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RV_POISSON_n (arg_mu);
  }
  break;

case OP_RV_RAYLEIGH_n:
  {
    double arg_sigma = *--ns;
    bool force_sysmis = !is_valid (arg_sigma) || !(arg_sigma > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RV_RAYLEIGH_n (arg_sigma);
  }
  break;

case OP_RV_RTAIL_nn:
  {
    double arg_sigma = *--ns;
    double arg_a = *--ns;
    bool force_sysmis = !is_valid (arg_a) || !is_valid (arg_sigma);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RV_RTAIL_nn (arg_a, arg_sigma);
  }
  break;

case OP_RV_T_n:
  {
    double arg_df = *--ns;
    bool force_sysmis = !is_valid (arg_df) || !(arg_df > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RV_T_n (arg_df);
  }
  break;

case OP_RV_T1G_nn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    bool force_sysmis = !is_valid (arg_a) || !is_valid (arg_b);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RV_T1G_nn (arg_a, arg_b);
  }
  break;

case OP_RV_T2G_nn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    bool force_sysmis = !is_valid (arg_a) || !is_valid (arg_b);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RV_T2G_nn (arg_a, arg_b);
  }
  break;

case OP_RV_UNIFORM_nn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    bool force_sysmis = !is_valid (arg_a) || !is_valid (arg_b) || !(arg_a <= arg_b);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RV_UNIFORM_nn (arg_a, arg_b);
  }
  break;

case OP_RV_WEIBULL_nn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    bool force_sysmis = !is_valid (arg_a) || !is_valid (arg_b) || !(arg_a > 0) || !(arg_b > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RV_WEIBULL_nn (arg_a, arg_b);
  }
  break;

case OP_RV_XPOWER_nn:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    bool force_sysmis = !is_valid (arg_a) || !is_valid (arg_b) || !(arg_a > 0) || !(arg_b >= 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_RV_XPOWER_nn (arg_a, arg_b);
  }
  break;

case OP_SD_n:
  {
    size_t arg_n = op++->integer;
    double *arg_a = ns -= arg_n;
    bool force_sysmis = count_valid (arg_a, arg_n) < op++->integer;
    *ns++ = force_sysmis ? SYSMIS : eval_OP_SD_n (arg_a, arg_n);
  }
  break;

case OP_SIG_CHISQ_nn:
  {
    double arg_df = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_df) || !(arg_x >= 0) || !(arg_df > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_SIG_CHISQ_nn (arg_x, arg_df);
  }
  break;

case OP_SIG_F_nnn:
  {
    double arg_df2 = *--ns;
    double arg_df1 = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_df1) || !is_valid (arg_df2) || !(arg_x >= 0) || !(arg_df1 > 0) || !(arg_df2 > 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_SIG_F_nnn (arg_x, arg_df1, arg_df2);
  }
  break;

case OP_SIN_n:
  {
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_SIN_n (arg_x);
  }
  break;

case OP_SQRT_n:
  {
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !(arg_x >= 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_SQRT_n (arg_x);
  }
  break;

case OP_STRING_nf:
  {
    double arg_x = *--ns;
    const struct fmt_spec *arg_f = op++->format;
    *ss++ = eval_OP_STRING_nf (arg_x, arg_f, e);
  }
  break;

case OP_STRUNC_sn:
  {
    double arg_n = *--ns;
    struct substring arg_s = *--ss;
    *ss++ = eval_OP_STRUNC_sn (arg_s, arg_n);
  }
  break;

case OP_SUBSTR_sn:
  {
    double arg_ofs = *--ns;
    struct substring arg_s = *--ss;
    *ss++ = eval_OP_SUBSTR_sn (arg_s, arg_ofs, e);
  }
  break;

case OP_SUBSTR_snn:
  {
    double arg_cnt = *--ns;
    double arg_ofs = *--ns;
    struct substring arg_s = *--ss;
    *ss++ = eval_OP_SUBSTR_snn (arg_s, arg_ofs, arg_cnt, e);
  }
  break;

case OP_SUM_n:
  {
    size_t arg_n = op++->integer;
    double *arg_a = ns -= arg_n;
    bool force_sysmis = count_valid (arg_a, arg_n) < op++->integer;
    *ns++ = force_sysmis ? SYSMIS : eval_OP_SUM_n (arg_a, arg_n);
  }
  break;

case OP_SYSMIS_Vn:
  {
    const struct variable *arg_v = op++->variable;
    *ns++ = eval_OP_SYSMIS_Vn (arg_v, c);
  }
  break;

case OP_SYSMIS_n:
  {
    double arg_x = *--ns;
    *ns++ = eval_OP_SYSMIS_n (arg_x);
  }
  break;

case OP_TAN_n:
  {
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_TAN_n (arg_x);
  }
  break;

case OP_TIME_DAYS_n:
  {
    double arg_days = *--ns;
    bool force_sysmis = !is_valid (arg_days);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_TIME_DAYS_n (arg_days);
  }
  break;

case OP_TIME_HMS_nnn:
  {
    double arg_s = *--ns;
    double arg_m = *--ns;
    double arg_h = *--ns;
    bool force_sysmis = !is_valid (arg_h) || !is_valid (arg_m) || !is_valid (arg_s);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_TIME_HMS_nnn (arg_h, arg_m, arg_s);
  }
  break;

case OP_TRUNC_n:
  {
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_TRUNC_n (arg_x);
  }
  break;

case OP_TRUNC_nn:
  {
    double arg_mult = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_mult) || !(arg_mult != 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_TRUNC_nn (arg_x, arg_mult);
  }
  break;

case OP_TRUNC_nnn:
  {
    double arg_fuzzbits = *--ns;
    double arg_mult = *--ns;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_mult) || !is_valid (arg_fuzzbits) || !(arg_mult != 0) || !(arg_fuzzbits >= 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_TRUNC_nnn (arg_x, arg_mult, arg_fuzzbits);
  }
  break;

case OP_UNIFORM_n:
  {
    double arg_b = *--ns;
    bool force_sysmis = !is_valid (arg_b) || !(arg_b >= 0);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_UNIFORM_n (arg_b);
  }
  break;

case OP_UPCASE_s:
  {
    struct substring arg_s = *--ss;
    *ss++ = eval_OP_UPCASE_s (arg_s);
  }
  break;

case OP_VALUE_Vn:
  {
    const struct variable *arg_v = op++->variable;
    *ns++ = eval_OP_VALUE_Vn (arg_v, c);
  }
  break;

case OP_VALUELABEL_V:
  {
    const struct variable *arg_v = op++->variable;
    *ss++ = eval_OP_VALUELABEL_V (arg_v, e, c);
  }
  break;

case OP_VARIANCE_n:
  {
    size_t arg_n = op++->integer;
    double *arg_a = ns -= arg_n;
    bool force_sysmis = count_valid (arg_a, arg_n) < op++->integer;
    *ns++ = force_sysmis ? SYSMIS : eval_OP_VARIANCE_n (arg_a, arg_n);
  }
  break;

case OP_XDATE_DATE_n:
  {
    double arg_date = *--ns;
    bool force_sysmis = !is_valid (arg_date);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_XDATE_DATE_n (arg_date);
  }
  break;

case OP_XDATE_HOUR_n:
  {
    double arg_date = *--ns;
    bool force_sysmis = !is_valid (arg_date);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_XDATE_HOUR_n (arg_date);
  }
  break;

case OP_XDATE_JDAY_n:
  {
    double arg_date = *--ns;
    bool force_sysmis = !is_valid (arg_date) || !(arg_date >= DAY_S);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_XDATE_JDAY_n (arg_date);
  }
  break;

case OP_XDATE_MDAY_n:
  {
    double arg_date = *--ns;
    bool force_sysmis = !is_valid (arg_date) || !(arg_date >= DAY_S);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_XDATE_MDAY_n (arg_date);
  }
  break;

case OP_XDATE_MINUTE_n:
  {
    double arg_date = *--ns;
    bool force_sysmis = !is_valid (arg_date);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_XDATE_MINUTE_n (arg_date);
  }
  break;

case OP_XDATE_MONTH_n:
  {
    double arg_date = *--ns;
    bool force_sysmis = !is_valid (arg_date) || !(arg_date >= DAY_S);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_XDATE_MONTH_n (arg_date);
  }
  break;

case OP_XDATE_QUARTER_n:
  {
    double arg_date = *--ns;
    bool force_sysmis = !is_valid (arg_date) || !(arg_date >= DAY_S);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_XDATE_QUARTER_n (arg_date);
  }
  break;

case OP_XDATE_SECOND_n:
  {
    double arg_date = *--ns;
    bool force_sysmis = !is_valid (arg_date);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_XDATE_SECOND_n (arg_date);
  }
  break;

case OP_XDATE_TDAY_n:
  {
    double arg_date = *--ns;
    bool force_sysmis = !is_valid (arg_date);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_XDATE_TDAY_n (arg_date);
  }
  break;

case OP_XDATE_TIME_n:
  {
    double arg_date = *--ns;
    bool force_sysmis = !is_valid (arg_date);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_XDATE_TIME_n (arg_date);
  }
  break;

case OP_XDATE_WEEK_n:
  {
    double arg_date = *--ns;
    bool force_sysmis = !is_valid (arg_date) || !(arg_date >= DAY_S);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_XDATE_WEEK_n (arg_date);
  }
  break;

case OP_XDATE_WKDAY_n:
  {
    double arg_date = *--ns;
    bool force_sysmis = !is_valid (arg_date) || !(arg_date >= DAY_S);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_XDATE_WKDAY_n (arg_date);
  }
  break;

case OP_XDATE_YEAR_n:
  {
    double arg_date = *--ns;
    bool force_sysmis = !is_valid (arg_date) || !(arg_date >= DAY_S);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_XDATE_YEAR_n (arg_date);
  }
  break;

case OP_YRMODA_nnn:
  {
    double arg_d = *--ns;
    double arg_m = *--ns;
    double arg_y = *--ns;
    bool force_sysmis = !is_valid (arg_y) || !is_valid (arg_m) || !is_valid (arg_d);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_YRMODA_nnn (arg_y, arg_m, arg_d);
  }
  break;

case OP_ADD:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    bool force_sysmis = !is_valid (arg_a) || !is_valid (arg_b);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_ADD (arg_a, arg_b);
  }
  break;

case OP_AND:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    *ns++ = eval_OP_AND (arg_a, arg_b);
  }
  break;

case OP_BOOLEAN_TO_NUM:
  {
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_BOOLEAN_TO_NUM (arg_x);
  }
  break;

case OP_CASENUM:
  *ns++ = eval_OP_CASENUM (case_idx);
  break;

case OP_DIV:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    *ns++ = eval_OP_DIV (arg_a, arg_b);
  }
  break;

case OP_EQ:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    bool force_sysmis = !is_valid (arg_a) || !is_valid (arg_b);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_EQ (arg_a, arg_b);
  }
  break;

case OP_EQ_STRING:
  {
    struct substring arg_b = *--ss;
    struct substring arg_a = *--ss;
    *ns++ = eval_OP_EQ_STRING (arg_a, arg_b);
  }
  break;

case OP_GE:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    bool force_sysmis = !is_valid (arg_a) || !is_valid (arg_b);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_GE (arg_a, arg_b);
  }
  break;

case OP_GE_STRING:
  {
    struct substring arg_b = *--ss;
    struct substring arg_a = *--ss;
    *ns++ = eval_OP_GE_STRING (arg_a, arg_b);
  }
  break;

case OP_GT:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    bool force_sysmis = !is_valid (arg_a) || !is_valid (arg_b);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_GT (arg_a, arg_b);
  }
  break;

case OP_GT_STRING:
  {
    struct substring arg_b = *--ss;
    struct substring arg_a = *--ss;
    *ns++ = eval_OP_GT_STRING (arg_a, arg_b);
  }
  break;

case OP_LE:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    bool force_sysmis = !is_valid (arg_a) || !is_valid (arg_b);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_LE (arg_a, arg_b);
  }
  break;

case OP_LE_STRING:
  {
    struct substring arg_b = *--ss;
    struct substring arg_a = *--ss;
    *ns++ = eval_OP_LE_STRING (arg_a, arg_b);
  }
  break;

case OP_LT:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    bool force_sysmis = !is_valid (arg_a) || !is_valid (arg_b);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_LT (arg_a, arg_b);
  }
  break;

case OP_LT_STRING:
  {
    struct substring arg_b = *--ss;
    struct substring arg_a = *--ss;
    *ns++ = eval_OP_LT_STRING (arg_a, arg_b);
  }
  break;

case OP_MUL:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    *ns++ = eval_OP_MUL (arg_a, arg_b);
  }
  break;

case OP_NE:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    bool force_sysmis = !is_valid (arg_a) || !is_valid (arg_b);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_NE (arg_a, arg_b);
  }
  break;

case OP_NEG:
  {
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_NEG (arg_x);
  }
  break;

case OP_NE_STRING:
  {
    struct substring arg_b = *--ss;
    struct substring arg_a = *--ss;
    *ns++ = eval_OP_NE_STRING (arg_a, arg_b);
  }
  break;

case OP_NOT:
  {
    double arg_a = *--ns;
    bool force_sysmis = !is_valid (arg_a);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_NOT (arg_a);
  }
  break;

case OP_NUM_SYS:
  {
    const struct variable *aux_v = op++->variable;
    *ns++ = eval_OP_NUM_SYS (c, aux_v);
  }
  break;

case OP_NUM_TO_BOOLEAN:
  {
    struct substring arg_op_name = *--ss;
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_NUM_TO_BOOLEAN (arg_x, arg_op_name);
  }
  break;

case OP_NUM_VAL:
  {
    const struct variable *aux_v = op++->variable;
    *ns++ = eval_OP_NUM_VAL (c, aux_v);
  }
  break;

case OP_NUM_VAR:
  {
    const struct variable *aux_v = op++->variable;
    *ns++ = eval_OP_NUM_VAR (c, aux_v);
  }
  break;

case OP_OR:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    *ns++ = eval_OP_OR (arg_a, arg_b);
  }
  break;

case OP_POW:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    *ns++ = eval_OP_POW (arg_a, arg_b);
  }
  break;

case OP_SQUARE:
  {
    double arg_x = *--ns;
    bool force_sysmis = !is_valid (arg_x);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_SQUARE (arg_x);
  }
  break;

case OP_STR_VAR:
  {
    const struct variable *aux_v = op++->variable;
    *ss++ = eval_OP_STR_VAR (c, e, aux_v);
  }
  break;

case OP_SUB:
  {
    double arg_b = *--ns;
    double arg_a = *--ns;
    bool force_sysmis = !is_valid (arg_a) || !is_valid (arg_b);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_SUB (arg_a, arg_b);
  }
  break;

case OP_VEC_ELEM_NUM:
  {
    double arg_idx = *--ns;
    const struct vector *aux_v = op++->vector;
    bool force_sysmis = !is_valid (arg_idx);
    *ns++ = force_sysmis ? SYSMIS : eval_OP_VEC_ELEM_NUM (arg_idx, aux_v, c);
  }
  break;

case OP_VEC_ELEM_STR:
  {
    double arg_idx = *--ns;
    const struct vector *aux_v = op++->vector;
    *ss++ = eval_OP_VEC_ELEM_STR (arg_idx, e, aux_v, c);
  }
  break;


/*
   Local Variables:
   mode: c
   buffer-read-only: t
   End:
*/
