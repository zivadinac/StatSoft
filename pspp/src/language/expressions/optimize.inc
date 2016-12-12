/* src/language/expressions/optimize.inc
   Generated from ./src/language/expressions/operations.def by generate.pl.  
   Do not modify! */

case OP_ABS_n:
  {
    double arg_x = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_x);
    double result = force_sysmis ? SYSMIS : eval_OP_ABS_n (arg_x);
    return expr_allocate_number (e, result);
  }

case OP_ACOS_n:
  {
    double arg_x = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_x) || !(arg_x >= -1 && arg_x <= 1);
    double result = force_sysmis ? SYSMIS : eval_OP_ACOS_n (arg_x);
    return expr_allocate_number (e, result);
  }

case OP_ANY_nn:
  {
    double arg_x = get_number_arg (node, 0);
    size_t arg_n = node->arg_cnt - 1;
    double *arg_a = get_number_args  (node, 1, arg_n, e);
    bool force_sysmis = !(arg_x != SYSMIS);
    double result = force_sysmis ? SYSMIS : eval_OP_ANY_nn (arg_x, arg_a, arg_n);
    return expr_allocate_boolean (e, result);
  }

case OP_ANY_ss:
  {
    struct substring arg_x = get_string_arg (node, 0);
    size_t arg_n = node->arg_cnt - 1;
    struct substring *arg_a = get_string_args  (node, 1, arg_n, e);
    return expr_allocate_boolean (e, eval_OP_ANY_ss (arg_x, arg_a, arg_n));
  }

case OP_ARCOS_n:
  {
    double arg_x = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_x) || !(arg_x >= -1 && arg_x <= 1);
    double result = force_sysmis ? SYSMIS : eval_OP_ARCOS_n (arg_x);
    return expr_allocate_number (e, result);
  }

case OP_ARSIN_n:
  {
    double arg_x = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_x) || !(arg_x >= -1 && arg_x <= 1);
    double result = force_sysmis ? SYSMIS : eval_OP_ARSIN_n (arg_x);
    return expr_allocate_number (e, result);
  }

case OP_ARTAN_n:
  {
    double arg_x = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_x);
    double result = force_sysmis ? SYSMIS : eval_OP_ARTAN_n (arg_x);
    return expr_allocate_number (e, result);
  }

case OP_ASIN_n:
  {
    double arg_x = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_x) || !(arg_x >= -1 && arg_x <= 1);
    double result = force_sysmis ? SYSMIS : eval_OP_ASIN_n (arg_x);
    return expr_allocate_number (e, result);
  }

case OP_ATAN_n:
  {
    double arg_x = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_x);
    double result = force_sysmis ? SYSMIS : eval_OP_ATAN_n (arg_x);
    return expr_allocate_number (e, result);
  }

case OP_CDF_BERNOULLI_nn:
  {
    double arg_k = get_number_arg (node, 0);
    double arg_p = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_k) || !is_valid (arg_p) || !(arg_k == 0 || arg_k == 1) || !(arg_p >= 0 && arg_p <= 1);
    double result = force_sysmis ? SYSMIS : eval_OP_CDF_BERNOULLI_nn (arg_k, arg_p);
    return expr_allocate_number (e, result);
  }

case OP_CDF_BETA_nnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_x >= 0 && arg_x <= 1) || !(arg_a > 0) || !(arg_b > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_CDF_BETA_nnn (arg_x, arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_CDF_BINOM_nnn:
  {
    double arg_k = get_number_arg (node, 0);
    double arg_n = get_number_arg (node, 1);
    double arg_p = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_k) || !is_valid (arg_n) || !is_valid (arg_p) || !(arg_n > 0 && arg_n == floor (arg_n)) || !(arg_p >= 0 && arg_p <= 1);
    double result = force_sysmis ? SYSMIS : eval_OP_CDF_BINOM_nnn (arg_k, arg_n, arg_p);
    return expr_allocate_number (e, result);
  }

case OP_CDF_BVNOR_nnn:
  {
    double arg_x0 = get_number_arg (node, 0);
    double arg_x1 = get_number_arg (node, 1);
    double arg_r = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x0) || !is_valid (arg_x1) || !is_valid (arg_r) || !(arg_r >= -1 && arg_r <= 1);
    double result = force_sysmis ? SYSMIS : eval_OP_CDF_BVNOR_nnn (arg_x0, arg_x1, arg_r);
    return expr_allocate_number (e, result);
  }

case OP_CDF_CAUCHY_nnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_b > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_CDF_CAUCHY_nnn (arg_x, arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_CDF_CHISQ_nn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_df = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_df) || !(arg_x >= 0) || !(arg_df > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_CDF_CHISQ_nn (arg_x, arg_df);
    return expr_allocate_number (e, result);
  }

case OP_CDF_EXP_nn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !(arg_x >= 0) || !(arg_a > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_CDF_EXP_nn (arg_x, arg_a);
    return expr_allocate_number (e, result);
  }

case OP_CDF_F_nnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_df1 = get_number_arg (node, 1);
    double arg_df2 = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_df1) || !is_valid (arg_df2) || !(arg_x >= 0) || !(arg_df1 > 0) || !(arg_df2 > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_CDF_F_nnn (arg_x, arg_df1, arg_df2);
    return expr_allocate_number (e, result);
  }

case OP_CDF_GAMMA_nnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_x >= 0) || !(arg_a > 0) || !(arg_b > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_CDF_GAMMA_nnn (arg_x, arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_CDF_GEOM_nn:
  {
    double arg_k = get_number_arg (node, 0);
    double arg_p = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_k) || !is_valid (arg_p) || !(arg_k >= 1 && arg_k == floor (arg_k)) || !(arg_p >= 0 && arg_p <= 1);
    double result = force_sysmis ? SYSMIS : eval_OP_CDF_GEOM_nn (arg_k, arg_p);
    return expr_allocate_number (e, result);
  }

case OP_CDF_HALFNRM_nnn:
  NOT_REACHED ();

case OP_CDF_HYPER_nnnn:
  {
    double arg_k = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    double arg_c = get_number_arg (node, 3);
    bool force_sysmis = !is_valid (arg_k) || !is_valid (arg_a) || !is_valid (arg_b) || !is_valid (arg_c) || !(arg_k >= 0 && arg_k == floor (arg_k) && arg_k <= arg_c) || !(arg_a > 0 && arg_a == floor (arg_a)) || !(arg_b > 0 && arg_b == floor (arg_b) && arg_b <= arg_a) || !(arg_c > 0 && arg_c == floor (arg_c) && arg_c <= arg_a);
    double result = force_sysmis ? SYSMIS : eval_OP_CDF_HYPER_nnnn (arg_k, arg_a, arg_b, arg_c);
    return expr_allocate_number (e, result);
  }

case OP_CDF_IGAUSS_nnn:
  NOT_REACHED ();

case OP_CDF_LAPLACE_nnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_b > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_CDF_LAPLACE_nnn (arg_x, arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_CDF_LNORMAL_nnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_m = get_number_arg (node, 1);
    double arg_s = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_m) || !is_valid (arg_s) || !(arg_x >= 0) || !(arg_m > 0) || !(arg_s > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_CDF_LNORMAL_nnn (arg_x, arg_m, arg_s);
    return expr_allocate_number (e, result);
  }

case OP_CDF_LOGISTIC_nnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_b > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_CDF_LOGISTIC_nnn (arg_x, arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_CDF_NEGBIN_nnn:
  {
    double arg_k = get_number_arg (node, 0);
    double arg_n = get_number_arg (node, 1);
    double arg_p = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_k) || !is_valid (arg_n) || !is_valid (arg_p) || !(arg_k >= 1) || !(arg_n == floor (arg_n)) || !(arg_p > 0 && arg_p <= 1);
    double result = force_sysmis ? SYSMIS : eval_OP_CDF_NEGBIN_nnn (arg_k, arg_n, arg_p);
    return expr_allocate_number (e, result);
  }

case OP_CDF_NORMAL_nnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_u = get_number_arg (node, 1);
    double arg_s = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_u) || !is_valid (arg_s) || !(arg_s > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_CDF_NORMAL_nnn (arg_x, arg_u, arg_s);
    return expr_allocate_number (e, result);
  }

case OP_CDF_PARETO_nnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_x >= arg_a) || !(arg_a > 0) || !(arg_b > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_CDF_PARETO_nnn (arg_x, arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_CDF_POISSON_nn:
  {
    double arg_k = get_number_arg (node, 0);
    double arg_mu = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_k) || !is_valid (arg_mu) || !(arg_k >= 0 && arg_k == floor (arg_k)) || !(arg_mu > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_CDF_POISSON_nn (arg_k, arg_mu);
    return expr_allocate_number (e, result);
  }

case OP_CDF_RAYLEIGH_nn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_sigma = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_sigma) || !(arg_sigma > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_CDF_RAYLEIGH_nn (arg_x, arg_sigma);
    return expr_allocate_number (e, result);
  }

case OP_CDF_SMOD_nnn:
  NOT_REACHED ();

case OP_CDF_SRANGE_nnn:
  NOT_REACHED ();

case OP_CDF_T_nn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_df = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_df) || !(arg_df > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_CDF_T_nn (arg_x, arg_df);
    return expr_allocate_number (e, result);
  }

case OP_CDF_T1G_nnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b);
    double result = force_sysmis ? SYSMIS : eval_OP_CDF_T1G_nnn (arg_x, arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_CDF_T2G_nnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b);
    double result = force_sysmis ? SYSMIS : eval_OP_CDF_T2G_nnn (arg_x, arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_CDF_UNIFORM_nnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_x <= arg_b) || !(arg_a <= arg_x);
    double result = force_sysmis ? SYSMIS : eval_OP_CDF_UNIFORM_nnn (arg_x, arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_CDF_WEIBULL_nnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_x >= 0) || !(arg_a > 0) || !(arg_b > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_CDF_WEIBULL_nnn (arg_x, arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_CDFNORM_n:
  {
    double arg_x = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_x);
    double result = force_sysmis ? SYSMIS : eval_OP_CDFNORM_n (arg_x);
    return expr_allocate_number (e, result);
  }

case OP_CFVAR_n:
  {
    size_t arg_n = node->arg_cnt;
    double *arg_a = get_number_args  (node, 0, arg_n, e);
    bool force_sysmis = count_valid (arg_a, arg_n) < node->min_valid;
    double result = force_sysmis ? SYSMIS : eval_OP_CFVAR_n (arg_a, arg_n);
    return expr_allocate_number (e, result);
  }

case OP_CONCAT_s:
  {
    size_t arg_n = node->arg_cnt;
    struct substring *arg_a = get_string_args  (node, 0, arg_n, e);
    return expr_allocate_string (e, eval_OP_CONCAT_s (arg_a, arg_n, e));
  }

case OP_COS_n:
  {
    double arg_x = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_x);
    double result = force_sysmis ? SYSMIS : eval_OP_COS_n (arg_x);
    return expr_allocate_number (e, result);
  }

case OP_CTIME_DAYS_n:
  {
    double arg_time = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_time);
    double result = force_sysmis ? SYSMIS : eval_OP_CTIME_DAYS_n (arg_time);
    return expr_allocate_number (e, result);
  }

case OP_CTIME_HOURS_n:
  {
    double arg_time = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_time);
    double result = force_sysmis ? SYSMIS : eval_OP_CTIME_HOURS_n (arg_time);
    return expr_allocate_number (e, result);
  }

case OP_CTIME_MINUTES_n:
  {
    double arg_time = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_time);
    double result = force_sysmis ? SYSMIS : eval_OP_CTIME_MINUTES_n (arg_time);
    return expr_allocate_number (e, result);
  }

case OP_CTIME_SECONDS_n:
  {
    double arg_time = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_time);
    double result = force_sysmis ? SYSMIS : eval_OP_CTIME_SECONDS_n (arg_time);
    return expr_allocate_number (e, result);
  }

case OP_DATE_DMY_nnn:
  {
    double arg_d = get_number_arg (node, 0);
    double arg_m = get_number_arg (node, 1);
    double arg_y = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_d) || !is_valid (arg_m) || !is_valid (arg_y);
    double result = force_sysmis ? SYSMIS : eval_OP_DATE_DMY_nnn (arg_d, arg_m, arg_y);
    return expr_allocate_number (e, result);
  }

case OP_DATE_MDY_nnn:
  {
    double arg_m = get_number_arg (node, 0);
    double arg_d = get_number_arg (node, 1);
    double arg_y = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_m) || !is_valid (arg_d) || !is_valid (arg_y);
    double result = force_sysmis ? SYSMIS : eval_OP_DATE_MDY_nnn (arg_m, arg_d, arg_y);
    return expr_allocate_number (e, result);
  }

case OP_DATE_MOYR_nn:
  {
    double arg_m = get_number_arg (node, 0);
    double arg_y = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_m) || !is_valid (arg_y);
    double result = force_sysmis ? SYSMIS : eval_OP_DATE_MOYR_nn (arg_m, arg_y);
    return expr_allocate_number (e, result);
  }

case OP_DATE_QYR_nn:
  {
    double arg_q = get_number_arg (node, 0);
    double arg_y = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_q) || !is_valid (arg_y);
    double result = force_sysmis ? SYSMIS : eval_OP_DATE_QYR_nn (arg_q, arg_y);
    return expr_allocate_number (e, result);
  }

case OP_DATE_WKYR_nn:
  {
    double arg_w = get_number_arg (node, 0);
    double arg_y = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_w) || !is_valid (arg_y);
    double result = force_sysmis ? SYSMIS : eval_OP_DATE_WKYR_nn (arg_w, arg_y);
    return expr_allocate_number (e, result);
  }

case OP_DATE_YRDAY_nn:
  {
    double arg_y = get_number_arg (node, 0);
    double arg_yday = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_y) || !is_valid (arg_yday);
    double result = force_sysmis ? SYSMIS : eval_OP_DATE_YRDAY_nn (arg_y, arg_yday);
    return expr_allocate_number (e, result);
  }

case OP_DATEDIFF_nns:
  {
    double arg_date2 = get_number_arg (node, 0);
    double arg_date1 = get_number_arg (node, 1);
    struct substring arg_unit = get_string_arg (node, 2);
    bool force_sysmis = !is_valid (arg_date2) || !is_valid (arg_date1) || !(arg_date2 >= DAY_S) || !(arg_date1 >= DAY_S);
    double result = force_sysmis ? SYSMIS : eval_OP_DATEDIFF_nns (arg_date2, arg_date1, arg_unit);
    return expr_allocate_number (e, result);
  }

case OP_DATESUM_nns:
  {
    double arg_date = get_number_arg (node, 0);
    double arg_quantity = get_number_arg (node, 1);
    struct substring arg_unit = get_string_arg (node, 2);
    bool force_sysmis = !is_valid (arg_date) || !is_valid (arg_quantity);
    double result = force_sysmis ? SYSMIS : eval_OP_DATESUM_nns (arg_date, arg_quantity, arg_unit);
    return expr_allocate_number (e, result);
  }

case OP_DATESUM_nnss:
  {
    double arg_date = get_number_arg (node, 0);
    double arg_quantity = get_number_arg (node, 1);
    struct substring arg_unit = get_string_arg (node, 2);
    struct substring arg_method = get_string_arg (node, 3);
    bool force_sysmis = !is_valid (arg_date) || !is_valid (arg_quantity);
    double result = force_sysmis ? SYSMIS : eval_OP_DATESUM_nnss (arg_date, arg_quantity, arg_unit, arg_method);
    return expr_allocate_number (e, result);
  }

case OP_EXP_n:
  {
    double arg_x = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_x);
    double result = force_sysmis ? SYSMIS : eval_OP_EXP_n (arg_x);
    return expr_allocate_number (e, result);
  }

case OP_IDF_BETA_nnn:
  {
    double arg_P = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_P >= 0 && arg_P <= 1) || !(arg_a > 0) || !(arg_b > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_IDF_BETA_nnn (arg_P, arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_IDF_CAUCHY_nnn:
  {
    double arg_P = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_P > 0 && arg_P < 1) || !(arg_b > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_IDF_CAUCHY_nnn (arg_P, arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_IDF_CHISQ_nn:
  {
    double arg_P = get_number_arg (node, 0);
    double arg_df = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_df) || !(arg_P >= 0 && arg_P < 1) || !(arg_df > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_IDF_CHISQ_nn (arg_P, arg_df);
    return expr_allocate_number (e, result);
  }

case OP_IDF_EXP_nn:
  {
    double arg_P = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_a) || !(arg_P >= 0 && arg_P < 1) || !(arg_a > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_IDF_EXP_nn (arg_P, arg_a);
    return expr_allocate_number (e, result);
  }

case OP_IDF_F_nnn:
  {
    double arg_P = get_number_arg (node, 0);
    double arg_df1 = get_number_arg (node, 1);
    double arg_df2 = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_df1) || !is_valid (arg_df2) || !(arg_P >= 0 && arg_P < 1) || !(arg_df1 > 0) || !(arg_df2 > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_IDF_F_nnn (arg_P, arg_df1, arg_df2);
    return expr_allocate_number (e, result);
  }

case OP_IDF_GAMMA_nnn:
  {
    double arg_P = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_P >= 0 && arg_P <= 1) || !(arg_a > 0) || !(arg_b > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_IDF_GAMMA_nnn (arg_P, arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_IDF_HALFNRM_nnn:
  NOT_REACHED ();

case OP_IDF_IGAUSS_nnn:
  NOT_REACHED ();

case OP_IDF_LAPLACE_nnn:
  {
    double arg_P = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_P > 0 && arg_P < 1) || !(arg_b > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_IDF_LAPLACE_nnn (arg_P, arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_IDF_LNORMAL_nnn:
  {
    double arg_P = get_number_arg (node, 0);
    double arg_m = get_number_arg (node, 1);
    double arg_s = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_m) || !is_valid (arg_s) || !(arg_P >= 0 && arg_P < 1) || !(arg_m > 0) || !(arg_s > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_IDF_LNORMAL_nnn (arg_P, arg_m, arg_s);
    return expr_allocate_number (e, result);
  }

case OP_IDF_LOGISTIC_nnn:
  {
    double arg_P = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_P > 0 && arg_P < 1) || !(arg_b > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_IDF_LOGISTIC_nnn (arg_P, arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_IDF_NORMAL_nnn:
  {
    double arg_P = get_number_arg (node, 0);
    double arg_u = get_number_arg (node, 1);
    double arg_s = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_u) || !is_valid (arg_s) || !(arg_P > 0 && arg_P < 1) || !(arg_s > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_IDF_NORMAL_nnn (arg_P, arg_u, arg_s);
    return expr_allocate_number (e, result);
  }

case OP_IDF_PARETO_nnn:
  {
    double arg_P = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_P >= 0 && arg_P < 1) || !(arg_a > 0) || !(arg_b > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_IDF_PARETO_nnn (arg_P, arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_IDF_RAYLEIGH_nn:
  {
    double arg_P = get_number_arg (node, 0);
    double arg_sigma = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_sigma) || !(arg_P >= 0 && arg_P <= 1) || !(arg_sigma > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_IDF_RAYLEIGH_nn (arg_P, arg_sigma);
    return expr_allocate_number (e, result);
  }

case OP_IDF_SMOD_nnn:
  NOT_REACHED ();

case OP_IDF_SRANGE_nnn:
  NOT_REACHED ();

case OP_IDF_T_nn:
  {
    double arg_P = get_number_arg (node, 0);
    double arg_df = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_df) || !(arg_P > 0 && arg_P < 1) || !(arg_df > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_IDF_T_nn (arg_P, arg_df);
    return expr_allocate_number (e, result);
  }

case OP_IDF_T1G_nnn:
  {
    double arg_P = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_P >= 0 && arg_P <= 1);
    double result = force_sysmis ? SYSMIS : eval_OP_IDF_T1G_nnn (arg_P, arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_IDF_T2G_nnn:
  {
    double arg_P = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_P >= 0 && arg_P <= 1);
    double result = force_sysmis ? SYSMIS : eval_OP_IDF_T2G_nnn (arg_P, arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_IDF_UNIFORM_nnn:
  {
    double arg_P = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_P >= 0 && arg_P <= 1) || !(arg_a <= arg_b);
    double result = force_sysmis ? SYSMIS : eval_OP_IDF_UNIFORM_nnn (arg_P, arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_IDF_WEIBULL_nnn:
  {
    double arg_P = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_P) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_P >= 0 && arg_P < 1) || !(arg_a > 0) || !(arg_b > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_IDF_WEIBULL_nnn (arg_P, arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_INDEX_ss:
  {
    struct substring arg_haystack = get_string_arg (node, 0);
    struct substring arg_needle = get_string_arg (node, 1);
    return expr_allocate_number (e, eval_OP_INDEX_ss (arg_haystack, arg_needle));
  }

case OP_INDEX_ssn:
  {
    struct substring arg_haystack = get_string_arg (node, 0);
    struct substring arg_needles = get_string_arg (node, 1);
    double arg_needle_len_d = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_needle_len_d);
    double result = force_sysmis ? SYSMIS : eval_OP_INDEX_ssn (arg_haystack, arg_needles, arg_needle_len_d);
    return expr_allocate_number (e, result);
  }

case OP_LAG_Vn:
  NOT_REACHED ();

case OP_LAG_Vnn:
  NOT_REACHED ();

case OP_LAG_Vs:
  NOT_REACHED ();

case OP_LAG_Vsn:
  NOT_REACHED ();

case OP_LENGTH_s:
  {
    struct substring arg_s = get_string_arg (node, 0);
    return expr_allocate_number (e, eval_OP_LENGTH_s (arg_s));
  }

case OP_LG10_n:
  {
    double arg_x = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_x);
    double result = force_sysmis ? SYSMIS : eval_OP_LG10_n (arg_x);
    return expr_allocate_number (e, result);
  }

case OP_LN_n:
  {
    double arg_x = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_x);
    double result = force_sysmis ? SYSMIS : eval_OP_LN_n (arg_x);
    return expr_allocate_number (e, result);
  }

case OP_LNGAMMA_n:
  {
    double arg_x = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_x) || !(arg_x >= 0);
    double result = force_sysmis ? SYSMIS : eval_OP_LNGAMMA_n (arg_x);
    return expr_allocate_number (e, result);
  }

case OP_LOWER_s:
  {
    struct substring arg_s = get_string_arg (node, 0);
    return expr_allocate_string (e, eval_OP_LOWER_s (arg_s));
  }

case OP_LPAD_sn:
  {
    struct substring arg_s = get_string_arg (node, 0);
    double arg_n = get_number_arg (node, 1);
    return expr_allocate_string (e, eval_OP_LPAD_sn (arg_s, arg_n, e));
  }

case OP_LPAD_sns:
  {
    struct substring arg_s = get_string_arg (node, 0);
    double arg_n = get_number_arg (node, 1);
    struct substring arg_c = get_string_arg (node, 2);
    return expr_allocate_string (e, eval_OP_LPAD_sns (arg_s, arg_n, arg_c, e));
  }

case OP_LTRIM_s:
  {
    struct substring arg_s = get_string_arg (node, 0);
    return expr_allocate_string (e, eval_OP_LTRIM_s (arg_s));
  }

case OP_LTRIM_ss:
  {
    struct substring arg_s = get_string_arg (node, 0);
    struct substring arg_c = get_string_arg (node, 1);
    return expr_allocate_string (e, eval_OP_LTRIM_ss (arg_s, arg_c));
  }

case OP_MAX_n:
  {
    size_t arg_n = node->arg_cnt;
    double *arg_a = get_number_args  (node, 0, arg_n, e);
    bool force_sysmis = count_valid (arg_a, arg_n) < node->min_valid;
    double result = force_sysmis ? SYSMIS : eval_OP_MAX_n (arg_a, arg_n);
    return expr_allocate_number (e, result);
  }

case OP_MAX_s:
  {
    size_t arg_n = node->arg_cnt;
    struct substring *arg_a = get_string_args  (node, 0, arg_n, e);
    return expr_allocate_string (e, eval_OP_MAX_s (arg_a, arg_n));
  }

case OP_MBLEN_BYTE_sn:
  {
    struct substring arg_s = get_string_arg (node, 0);
    double arg_idx = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_idx);
    double result = force_sysmis ? SYSMIS : eval_OP_MBLEN_BYTE_sn (arg_s, arg_idx);
    return expr_allocate_number (e, result);
  }

case OP_MEAN_n:
  {
    size_t arg_n = node->arg_cnt;
    double *arg_a = get_number_args  (node, 0, arg_n, e);
    bool force_sysmis = count_valid (arg_a, arg_n) < node->min_valid;
    double result = force_sysmis ? SYSMIS : eval_OP_MEAN_n (arg_a, arg_n);
    return expr_allocate_number (e, result);
  }

case OP_MEDIAN_n:
  {
    size_t arg_n = node->arg_cnt;
    double *arg_a = get_number_args  (node, 0, arg_n, e);
    bool force_sysmis = count_valid (arg_a, arg_n) < node->min_valid;
    double result = force_sysmis ? SYSMIS : eval_OP_MEDIAN_n (arg_a, arg_n);
    return expr_allocate_number (e, result);
  }

case OP_MIN_n:
  {
    size_t arg_n = node->arg_cnt;
    double *arg_a = get_number_args  (node, 0, arg_n, e);
    bool force_sysmis = count_valid (arg_a, arg_n) < node->min_valid;
    double result = force_sysmis ? SYSMIS : eval_OP_MIN_n (arg_a, arg_n);
    return expr_allocate_number (e, result);
  }

case OP_MIN_s:
  {
    size_t arg_n = node->arg_cnt;
    struct substring *arg_a = get_string_args  (node, 0, arg_n, e);
    return expr_allocate_string (e, eval_OP_MIN_s (arg_a, arg_n));
  }

case OP_MISSING_n:
  {
    double arg_x = get_number_arg (node, 0);
    return expr_allocate_boolean (e, eval_OP_MISSING_n (arg_x));
  }

case OP_MOD_nn:
  {
    double arg_n = get_number_arg (node, 0);
    double arg_d = get_number_arg (node, 1);
    return expr_allocate_number (e, eval_OP_MOD_nn (arg_n, arg_d));
  }

case OP_MOD10_n:
  {
    double arg_x = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_x);
    double result = force_sysmis ? SYSMIS : eval_OP_MOD10_n (arg_x);
    return expr_allocate_number (e, result);
  }

case OP_NCDF_BETA_nnnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    double arg_lambda = get_number_arg (node, 3);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !is_valid (arg_lambda) || !(arg_x >= 0) || !(arg_a > 0) || !(arg_b > 0) || !(arg_lambda > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_NCDF_BETA_nnnn (arg_x, arg_a, arg_b, arg_lambda);
    return expr_allocate_number (e, result);
  }

case OP_NCDF_CHISQ_nnn:
  NOT_REACHED ();

case OP_NCDF_F_nnnn:
  NOT_REACHED ();

case OP_NCDF_T_nnn:
  NOT_REACHED ();

case OP_NMISS_n:
  {
    size_t arg_n = node->arg_cnt;
    double *arg_a = get_number_args  (node, 0, arg_n, e);
    return expr_allocate_number (e, eval_OP_NMISS_n (arg_a, arg_n));
  }

case OP_NORMAL_n:
  NOT_REACHED ();

case OP_NPDF_BETA_nnnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    double arg_lambda = get_number_arg (node, 3);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !is_valid (arg_lambda) || !(arg_x >= 0) || !(arg_a > 0) || !(arg_b > 0) || !(arg_lambda > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_NPDF_BETA_nnnn (arg_x, arg_a, arg_b, arg_lambda);
    return expr_allocate_number (e, result);
  }

case OP_NPDF_CHISQ_nnn:
  NOT_REACHED ();

case OP_NPDF_F_nnnn:
  NOT_REACHED ();

case OP_NPDF_T_nnn:
  NOT_REACHED ();

case OP_NUMBER_sf:
  {
    struct substring arg_s = get_string_arg (node, 0);
    const struct fmt_spec *arg_f = get_format_arg (node, 1);
    return expr_allocate_number (e, eval_OP_NUMBER_sf (arg_s, arg_f));
  }

case OP_NVALID_n:
  {
    size_t arg_n = node->arg_cnt;
    double *arg_a = get_number_args  (node, 0, arg_n, e);
    return expr_allocate_number (e, eval_OP_NVALID_n (arg_a, arg_n));
  }

case OP_PDF_BERNOULLI_nn:
  {
    double arg_k = get_number_arg (node, 0);
    double arg_p = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_k) || !is_valid (arg_p) || !(arg_k == 0 || arg_k == 1) || !(arg_p >= 0 && arg_p <= 1);
    double result = force_sysmis ? SYSMIS : eval_OP_PDF_BERNOULLI_nn (arg_k, arg_p);
    return expr_allocate_number (e, result);
  }

case OP_PDF_BETA_nnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_x >= 0 && arg_x <= 1) || !(arg_a > 0) || !(arg_b > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_PDF_BETA_nnn (arg_x, arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_PDF_BINOM_nnn:
  {
    double arg_k = get_number_arg (node, 0);
    double arg_n = get_number_arg (node, 1);
    double arg_p = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_k) || !is_valid (arg_n) || !is_valid (arg_p) || !(arg_k >= 0 && arg_k == floor (arg_k) && arg_k <= arg_n) || !(arg_n > 0 && arg_n == floor (arg_n)) || !(arg_p >= 0 && arg_p <= 1);
    double result = force_sysmis ? SYSMIS : eval_OP_PDF_BINOM_nnn (arg_k, arg_n, arg_p);
    return expr_allocate_number (e, result);
  }

case OP_PDF_BVNOR_nnn:
  {
    double arg_x0 = get_number_arg (node, 0);
    double arg_x1 = get_number_arg (node, 1);
    double arg_r = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x0) || !is_valid (arg_x1) || !is_valid (arg_r) || !(arg_r >= -1 && arg_r <= 1);
    double result = force_sysmis ? SYSMIS : eval_OP_PDF_BVNOR_nnn (arg_x0, arg_x1, arg_r);
    return expr_allocate_number (e, result);
  }

case OP_PDF_CAUCHY_nnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_b > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_PDF_CAUCHY_nnn (arg_x, arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_PDF_CHISQ_nn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_df = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_df) || !(arg_x >= 0) || !(arg_df > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_PDF_CHISQ_nn (arg_x, arg_df);
    return expr_allocate_number (e, result);
  }

case OP_PDF_EXP_nn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !(arg_x >= 0) || !(arg_a > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_PDF_EXP_nn (arg_x, arg_a);
    return expr_allocate_number (e, result);
  }

case OP_PDF_F_nnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_df1 = get_number_arg (node, 1);
    double arg_df2 = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_df1) || !is_valid (arg_df2) || !(arg_x >= 0) || !(arg_df1 > 0) || !(arg_df2 > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_PDF_F_nnn (arg_x, arg_df1, arg_df2);
    return expr_allocate_number (e, result);
  }

case OP_PDF_GAMMA_nnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_x >= 0) || !(arg_a > 0) || !(arg_b > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_PDF_GAMMA_nnn (arg_x, arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_PDF_GEOM_nn:
  {
    double arg_k = get_number_arg (node, 0);
    double arg_p = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_k) || !is_valid (arg_p) || !(arg_k >= 1 && arg_k == floor (arg_k)) || !(arg_p >= 0 && arg_p <= 1);
    double result = force_sysmis ? SYSMIS : eval_OP_PDF_GEOM_nn (arg_k, arg_p);
    return expr_allocate_number (e, result);
  }

case OP_PDF_HALFNRM_nnn:
  NOT_REACHED ();

case OP_PDF_HYPER_nnnn:
  {
    double arg_k = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    double arg_c = get_number_arg (node, 3);
    bool force_sysmis = !is_valid (arg_k) || !is_valid (arg_a) || !is_valid (arg_b) || !is_valid (arg_c) || !(arg_k >= 0 && arg_k == floor (arg_k) && arg_k <= arg_c) || !(arg_a > 0 && arg_a == floor (arg_a)) || !(arg_b > 0 && arg_b == floor (arg_b) && arg_b <= arg_a) || !(arg_c > 0 && arg_c == floor (arg_c) && arg_c <= arg_a);
    double result = force_sysmis ? SYSMIS : eval_OP_PDF_HYPER_nnnn (arg_k, arg_a, arg_b, arg_c);
    return expr_allocate_number (e, result);
  }

case OP_PDF_IGAUSS_nnn:
  NOT_REACHED ();

case OP_PDF_LANDAU_n:
  {
    double arg_x = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_x);
    double result = force_sysmis ? SYSMIS : eval_OP_PDF_LANDAU_n (arg_x);
    return expr_allocate_number (e, result);
  }

case OP_PDF_LAPLACE_nnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_b > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_PDF_LAPLACE_nnn (arg_x, arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_PDF_LNORMAL_nnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_m = get_number_arg (node, 1);
    double arg_s = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_m) || !is_valid (arg_s) || !(arg_x >= 0) || !(arg_m > 0) || !(arg_s > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_PDF_LNORMAL_nnn (arg_x, arg_m, arg_s);
    return expr_allocate_number (e, result);
  }

case OP_PDF_LOG_nn:
  {
    double arg_k = get_number_arg (node, 0);
    double arg_p = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_k) || !is_valid (arg_p) || !(arg_k >= 1) || !(arg_p > 0 && arg_p <= 1);
    double result = force_sysmis ? SYSMIS : eval_OP_PDF_LOG_nn (arg_k, arg_p);
    return expr_allocate_number (e, result);
  }

case OP_PDF_LOGISTIC_nnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_b > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_PDF_LOGISTIC_nnn (arg_x, arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_PDF_NEGBIN_nnn:
  {
    double arg_k = get_number_arg (node, 0);
    double arg_n = get_number_arg (node, 1);
    double arg_p = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_k) || !is_valid (arg_n) || !is_valid (arg_p) || !(arg_k >= 1) || !(arg_n == floor (arg_n)) || !(arg_p > 0 && arg_p <= 1);
    double result = force_sysmis ? SYSMIS : eval_OP_PDF_NEGBIN_nnn (arg_k, arg_n, arg_p);
    return expr_allocate_number (e, result);
  }

case OP_PDF_NORMAL_nnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_u = get_number_arg (node, 1);
    double arg_s = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_u) || !is_valid (arg_s) || !(arg_s > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_PDF_NORMAL_nnn (arg_x, arg_u, arg_s);
    return expr_allocate_number (e, result);
  }

case OP_PDF_NTAIL_nnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_sigma = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_sigma) || !(arg_a > 0) || !(arg_sigma > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_PDF_NTAIL_nnn (arg_x, arg_a, arg_sigma);
    return expr_allocate_number (e, result);
  }

case OP_PDF_PARETO_nnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_x >= arg_a) || !(arg_a > 0) || !(arg_b > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_PDF_PARETO_nnn (arg_x, arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_PDF_POISSON_nn:
  {
    double arg_k = get_number_arg (node, 0);
    double arg_mu = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_k) || !is_valid (arg_mu) || !(arg_k >= 0 && arg_k == floor (arg_k)) || !(arg_mu > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_PDF_POISSON_nn (arg_k, arg_mu);
    return expr_allocate_number (e, result);
  }

case OP_PDF_RAYLEIGH_nn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_sigma = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_sigma) || !(arg_sigma > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_PDF_RAYLEIGH_nn (arg_x, arg_sigma);
    return expr_allocate_number (e, result);
  }

case OP_PDF_RTAIL_nnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_sigma = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_sigma);
    double result = force_sysmis ? SYSMIS : eval_OP_PDF_RTAIL_nnn (arg_x, arg_a, arg_sigma);
    return expr_allocate_number (e, result);
  }

case OP_PDF_T_nn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_df = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_df) || !(arg_df > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_PDF_T_nn (arg_x, arg_df);
    return expr_allocate_number (e, result);
  }

case OP_PDF_T1G_nnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b);
    double result = force_sysmis ? SYSMIS : eval_OP_PDF_T1G_nnn (arg_x, arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_PDF_T2G_nnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b);
    double result = force_sysmis ? SYSMIS : eval_OP_PDF_T2G_nnn (arg_x, arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_PDF_UNIFORM_nnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_x <= arg_b) || !(arg_a <= arg_x);
    double result = force_sysmis ? SYSMIS : eval_OP_PDF_UNIFORM_nnn (arg_x, arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_PDF_WEIBULL_nnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_x >= 0) || !(arg_a > 0) || !(arg_b > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_PDF_WEIBULL_nnn (arg_x, arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_PDF_XPOWER_nnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_a = get_number_arg (node, 1);
    double arg_b = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_a) || !is_valid (arg_b) || !(arg_a > 0) || !(arg_b >= 0);
    double result = force_sysmis ? SYSMIS : eval_OP_PDF_XPOWER_nnn (arg_x, arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_PROBIT_n:
  {
    double arg_P = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_P) || !(arg_P > 0 && arg_P < 1);
    double result = force_sysmis ? SYSMIS : eval_OP_PROBIT_n (arg_P);
    return expr_allocate_number (e, result);
  }

case OP_RANGE_nn:
  {
    double arg_x = get_number_arg (node, 0);
    size_t arg_n = node->arg_cnt - 1;
    double *arg_a = get_number_args  (node, 1, arg_n, e);
    bool force_sysmis = !(arg_x != SYSMIS);
    double result = force_sysmis ? SYSMIS : eval_OP_RANGE_nn (arg_x, arg_a, arg_n / 2);
    return expr_allocate_boolean (e, result);
  }

case OP_RANGE_ss:
  {
    struct substring arg_x = get_string_arg (node, 0);
    size_t arg_n = node->arg_cnt - 1;
    struct substring *arg_a = get_string_args  (node, 1, arg_n, e);
    return expr_allocate_boolean (e, eval_OP_RANGE_ss (arg_x, arg_a, arg_n / 2));
  }

case OP_REPLACE_sss:
  {
    struct substring arg_haystack = get_string_arg (node, 0);
    struct substring arg_needle = get_string_arg (node, 1);
    struct substring arg_replacement = get_string_arg (node, 2);
    return expr_allocate_string (e, eval_OP_REPLACE_sss (arg_haystack, arg_needle, arg_replacement, e));
  }

case OP_REPLACE_sssn:
  {
    struct substring arg_haystack = get_string_arg (node, 0);
    struct substring arg_needle = get_string_arg (node, 1);
    struct substring arg_replacement = get_string_arg (node, 2);
    double arg_n = get_number_arg (node, 3);
    return expr_allocate_string (e, eval_OP_REPLACE_sssn (arg_haystack, arg_needle, arg_replacement, arg_n, e));
  }

case OP_RINDEX_ss:
  {
    struct substring arg_haystack = get_string_arg (node, 0);
    struct substring arg_needle = get_string_arg (node, 1);
    return expr_allocate_number (e, eval_OP_RINDEX_ss (arg_haystack, arg_needle));
  }

case OP_RINDEX_ssn:
  {
    struct substring arg_haystack = get_string_arg (node, 0);
    struct substring arg_needles = get_string_arg (node, 1);
    double arg_needle_len_d = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_needle_len_d);
    double result = force_sysmis ? SYSMIS : eval_OP_RINDEX_ssn (arg_haystack, arg_needles, arg_needle_len_d);
    return expr_allocate_number (e, result);
  }

case OP_RND_n:
  {
    double arg_x = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_x);
    double result = force_sysmis ? SYSMIS : eval_OP_RND_n (arg_x);
    return expr_allocate_number (e, result);
  }

case OP_RND_nn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_mult = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_mult) || !(arg_mult != 0);
    double result = force_sysmis ? SYSMIS : eval_OP_RND_nn (arg_x, arg_mult);
    return expr_allocate_number (e, result);
  }

case OP_RND_nnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_mult = get_number_arg (node, 1);
    double arg_fuzzbits = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_mult) || !is_valid (arg_fuzzbits) || !(arg_mult != 0) || !(arg_fuzzbits >= 0);
    double result = force_sysmis ? SYSMIS : eval_OP_RND_nnn (arg_x, arg_mult, arg_fuzzbits);
    return expr_allocate_number (e, result);
  }

case OP_RPAD_sn:
  {
    struct substring arg_s = get_string_arg (node, 0);
    double arg_n = get_number_arg (node, 1);
    return expr_allocate_string (e, eval_OP_RPAD_sn (arg_s, arg_n, e));
  }

case OP_RPAD_sns:
  {
    struct substring arg_s = get_string_arg (node, 0);
    double arg_n = get_number_arg (node, 1);
    struct substring arg_c = get_string_arg (node, 2);
    return expr_allocate_string (e, eval_OP_RPAD_sns (arg_s, arg_n, arg_c, e));
  }

case OP_RTRIM_s:
  {
    struct substring arg_s = get_string_arg (node, 0);
    return expr_allocate_string (e, eval_OP_RTRIM_s (arg_s));
  }

case OP_RTRIM_ss:
  {
    struct substring arg_s = get_string_arg (node, 0);
    struct substring arg_c = get_string_arg (node, 1);
    return expr_allocate_string (e, eval_OP_RTRIM_ss (arg_s, arg_c));
  }

case OP_RV_BERNOULLI_n:
  NOT_REACHED ();

case OP_RV_BETA_nn:
  NOT_REACHED ();

case OP_RV_BINOM_nn:
  NOT_REACHED ();

case OP_RV_CAUCHY_nn:
  NOT_REACHED ();

case OP_RV_CHISQ_n:
  NOT_REACHED ();

case OP_RV_EXP_n:
  NOT_REACHED ();

case OP_RV_F_nn:
  NOT_REACHED ();

case OP_RV_GAMMA_nn:
  NOT_REACHED ();

case OP_RV_GEOM_n:
  NOT_REACHED ();

case OP_RV_HALFNRM_nn:
  NOT_REACHED ();

case OP_RV_HYPER_nnn:
  NOT_REACHED ();

case OP_RV_IGAUSS_nn:
  NOT_REACHED ();

case OP_RV_LANDAU_:
  NOT_REACHED ();

case OP_RV_LAPLACE_nn:
  NOT_REACHED ();

case OP_RV_LEVY_nn:
  NOT_REACHED ();

case OP_RV_LNORMAL_nn:
  NOT_REACHED ();

case OP_RV_LOG_n:
  NOT_REACHED ();

case OP_RV_LOGISTIC_nn:
  NOT_REACHED ();

case OP_RV_LVSKEW_nnn:
  NOT_REACHED ();

case OP_RV_NEGBIN_nn:
  NOT_REACHED ();

case OP_RV_NORMAL_nn:
  NOT_REACHED ();

case OP_RV_NTAIL_nn:
  NOT_REACHED ();

case OP_RV_PARETO_nn:
  NOT_REACHED ();

case OP_RV_POISSON_n:
  NOT_REACHED ();

case OP_RV_RAYLEIGH_n:
  NOT_REACHED ();

case OP_RV_RTAIL_nn:
  NOT_REACHED ();

case OP_RV_T_n:
  NOT_REACHED ();

case OP_RV_T1G_nn:
  NOT_REACHED ();

case OP_RV_T2G_nn:
  NOT_REACHED ();

case OP_RV_UNIFORM_nn:
  NOT_REACHED ();

case OP_RV_WEIBULL_nn:
  NOT_REACHED ();

case OP_RV_XPOWER_nn:
  NOT_REACHED ();

case OP_SD_n:
  {
    size_t arg_n = node->arg_cnt;
    double *arg_a = get_number_args  (node, 0, arg_n, e);
    bool force_sysmis = count_valid (arg_a, arg_n) < node->min_valid;
    double result = force_sysmis ? SYSMIS : eval_OP_SD_n (arg_a, arg_n);
    return expr_allocate_number (e, result);
  }

case OP_SIG_CHISQ_nn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_df = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_df) || !(arg_x >= 0) || !(arg_df > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_SIG_CHISQ_nn (arg_x, arg_df);
    return expr_allocate_number (e, result);
  }

case OP_SIG_F_nnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_df1 = get_number_arg (node, 1);
    double arg_df2 = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_df1) || !is_valid (arg_df2) || !(arg_x >= 0) || !(arg_df1 > 0) || !(arg_df2 > 0);
    double result = force_sysmis ? SYSMIS : eval_OP_SIG_F_nnn (arg_x, arg_df1, arg_df2);
    return expr_allocate_number (e, result);
  }

case OP_SIN_n:
  {
    double arg_x = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_x);
    double result = force_sysmis ? SYSMIS : eval_OP_SIN_n (arg_x);
    return expr_allocate_number (e, result);
  }

case OP_SQRT_n:
  {
    double arg_x = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_x) || !(arg_x >= 0);
    double result = force_sysmis ? SYSMIS : eval_OP_SQRT_n (arg_x);
    return expr_allocate_number (e, result);
  }

case OP_STRING_nf:
  {
    double arg_x = get_number_arg (node, 0);
    const struct fmt_spec *arg_f = get_format_arg (node, 1);
    return expr_allocate_string (e, eval_OP_STRING_nf (arg_x, arg_f, e));
  }

case OP_STRUNC_sn:
  {
    struct substring arg_s = get_string_arg (node, 0);
    double arg_n = get_number_arg (node, 1);
    return expr_allocate_string (e, eval_OP_STRUNC_sn (arg_s, arg_n));
  }

case OP_SUBSTR_sn:
  {
    struct substring arg_s = get_string_arg (node, 0);
    double arg_ofs = get_number_arg (node, 1);
    return expr_allocate_string (e, eval_OP_SUBSTR_sn (arg_s, arg_ofs, e));
  }

case OP_SUBSTR_snn:
  {
    struct substring arg_s = get_string_arg (node, 0);
    double arg_ofs = get_number_arg (node, 1);
    double arg_cnt = get_number_arg (node, 2);
    return expr_allocate_string (e, eval_OP_SUBSTR_snn (arg_s, arg_ofs, arg_cnt, e));
  }

case OP_SUM_n:
  {
    size_t arg_n = node->arg_cnt;
    double *arg_a = get_number_args  (node, 0, arg_n, e);
    bool force_sysmis = count_valid (arg_a, arg_n) < node->min_valid;
    double result = force_sysmis ? SYSMIS : eval_OP_SUM_n (arg_a, arg_n);
    return expr_allocate_number (e, result);
  }

case OP_SYSMIS_Vn:
  NOT_REACHED ();

case OP_SYSMIS_n:
  {
    double arg_x = get_number_arg (node, 0);
    return expr_allocate_boolean (e, eval_OP_SYSMIS_n (arg_x));
  }

case OP_TAN_n:
  {
    double arg_x = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_x);
    double result = force_sysmis ? SYSMIS : eval_OP_TAN_n (arg_x);
    return expr_allocate_number (e, result);
  }

case OP_TIME_DAYS_n:
  {
    double arg_days = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_days);
    double result = force_sysmis ? SYSMIS : eval_OP_TIME_DAYS_n (arg_days);
    return expr_allocate_number (e, result);
  }

case OP_TIME_HMS_nnn:
  {
    double arg_h = get_number_arg (node, 0);
    double arg_m = get_number_arg (node, 1);
    double arg_s = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_h) || !is_valid (arg_m) || !is_valid (arg_s);
    double result = force_sysmis ? SYSMIS : eval_OP_TIME_HMS_nnn (arg_h, arg_m, arg_s);
    return expr_allocate_number (e, result);
  }

case OP_TRUNC_n:
  {
    double arg_x = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_x);
    double result = force_sysmis ? SYSMIS : eval_OP_TRUNC_n (arg_x);
    return expr_allocate_number (e, result);
  }

case OP_TRUNC_nn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_mult = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_mult) || !(arg_mult != 0);
    double result = force_sysmis ? SYSMIS : eval_OP_TRUNC_nn (arg_x, arg_mult);
    return expr_allocate_number (e, result);
  }

case OP_TRUNC_nnn:
  {
    double arg_x = get_number_arg (node, 0);
    double arg_mult = get_number_arg (node, 1);
    double arg_fuzzbits = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_x) || !is_valid (arg_mult) || !is_valid (arg_fuzzbits) || !(arg_mult != 0) || !(arg_fuzzbits >= 0);
    double result = force_sysmis ? SYSMIS : eval_OP_TRUNC_nnn (arg_x, arg_mult, arg_fuzzbits);
    return expr_allocate_number (e, result);
  }

case OP_UNIFORM_n:
  NOT_REACHED ();

case OP_UPCASE_s:
  {
    struct substring arg_s = get_string_arg (node, 0);
    return expr_allocate_string (e, eval_OP_UPCASE_s (arg_s));
  }

case OP_VALUE_Vn:
  NOT_REACHED ();

case OP_VALUELABEL_V:
  NOT_REACHED ();

case OP_VARIANCE_n:
  {
    size_t arg_n = node->arg_cnt;
    double *arg_a = get_number_args  (node, 0, arg_n, e);
    bool force_sysmis = count_valid (arg_a, arg_n) < node->min_valid;
    double result = force_sysmis ? SYSMIS : eval_OP_VARIANCE_n (arg_a, arg_n);
    return expr_allocate_number (e, result);
  }

case OP_XDATE_DATE_n:
  {
    double arg_date = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_date);
    double result = force_sysmis ? SYSMIS : eval_OP_XDATE_DATE_n (arg_date);
    return expr_allocate_number (e, result);
  }

case OP_XDATE_HOUR_n:
  {
    double arg_date = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_date);
    double result = force_sysmis ? SYSMIS : eval_OP_XDATE_HOUR_n (arg_date);
    return expr_allocate_number (e, result);
  }

case OP_XDATE_JDAY_n:
  {
    double arg_date = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_date) || !(arg_date >= DAY_S);
    double result = force_sysmis ? SYSMIS : eval_OP_XDATE_JDAY_n (arg_date);
    return expr_allocate_number (e, result);
  }

case OP_XDATE_MDAY_n:
  {
    double arg_date = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_date) || !(arg_date >= DAY_S);
    double result = force_sysmis ? SYSMIS : eval_OP_XDATE_MDAY_n (arg_date);
    return expr_allocate_number (e, result);
  }

case OP_XDATE_MINUTE_n:
  {
    double arg_date = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_date);
    double result = force_sysmis ? SYSMIS : eval_OP_XDATE_MINUTE_n (arg_date);
    return expr_allocate_number (e, result);
  }

case OP_XDATE_MONTH_n:
  {
    double arg_date = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_date) || !(arg_date >= DAY_S);
    double result = force_sysmis ? SYSMIS : eval_OP_XDATE_MONTH_n (arg_date);
    return expr_allocate_number (e, result);
  }

case OP_XDATE_QUARTER_n:
  {
    double arg_date = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_date) || !(arg_date >= DAY_S);
    double result = force_sysmis ? SYSMIS : eval_OP_XDATE_QUARTER_n (arg_date);
    return expr_allocate_number (e, result);
  }

case OP_XDATE_SECOND_n:
  {
    double arg_date = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_date);
    double result = force_sysmis ? SYSMIS : eval_OP_XDATE_SECOND_n (arg_date);
    return expr_allocate_number (e, result);
  }

case OP_XDATE_TDAY_n:
  {
    double arg_date = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_date);
    double result = force_sysmis ? SYSMIS : eval_OP_XDATE_TDAY_n (arg_date);
    return expr_allocate_number (e, result);
  }

case OP_XDATE_TIME_n:
  {
    double arg_date = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_date);
    double result = force_sysmis ? SYSMIS : eval_OP_XDATE_TIME_n (arg_date);
    return expr_allocate_number (e, result);
  }

case OP_XDATE_WEEK_n:
  {
    double arg_date = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_date) || !(arg_date >= DAY_S);
    double result = force_sysmis ? SYSMIS : eval_OP_XDATE_WEEK_n (arg_date);
    return expr_allocate_number (e, result);
  }

case OP_XDATE_WKDAY_n:
  {
    double arg_date = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_date) || !(arg_date >= DAY_S);
    double result = force_sysmis ? SYSMIS : eval_OP_XDATE_WKDAY_n (arg_date);
    return expr_allocate_number (e, result);
  }

case OP_XDATE_YEAR_n:
  {
    double arg_date = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_date) || !(arg_date >= DAY_S);
    double result = force_sysmis ? SYSMIS : eval_OP_XDATE_YEAR_n (arg_date);
    return expr_allocate_number (e, result);
  }

case OP_YRMODA_nnn:
  {
    double arg_y = get_number_arg (node, 0);
    double arg_m = get_number_arg (node, 1);
    double arg_d = get_number_arg (node, 2);
    bool force_sysmis = !is_valid (arg_y) || !is_valid (arg_m) || !is_valid (arg_d);
    double result = force_sysmis ? SYSMIS : eval_OP_YRMODA_nnn (arg_y, arg_m, arg_d);
    return expr_allocate_number (e, result);
  }

case OP_ADD:
  {
    double arg_a = get_number_arg (node, 0);
    double arg_b = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_a) || !is_valid (arg_b);
    double result = force_sysmis ? SYSMIS : eval_OP_ADD (arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_AND:
  {
    double arg_a = get_number_arg (node, 0);
    double arg_b = get_number_arg (node, 1);
    return expr_allocate_boolean (e, eval_OP_AND (arg_a, arg_b));
  }

case OP_BOOLEAN_TO_NUM:
  {
    double arg_x = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_x);
    double result = force_sysmis ? SYSMIS : eval_OP_BOOLEAN_TO_NUM (arg_x);
    return expr_allocate_number (e, result);
  }

case OP_CASENUM:
  NOT_REACHED ();

case OP_DIV:
  {
    double arg_a = get_number_arg (node, 0);
    double arg_b = get_number_arg (node, 1);
    return expr_allocate_number (e, eval_OP_DIV (arg_a, arg_b));
  }

case OP_EQ:
  {
    double arg_a = get_number_arg (node, 0);
    double arg_b = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_a) || !is_valid (arg_b);
    double result = force_sysmis ? SYSMIS : eval_OP_EQ (arg_a, arg_b);
    return expr_allocate_boolean (e, result);
  }

case OP_EQ_STRING:
  {
    struct substring arg_a = get_string_arg (node, 0);
    struct substring arg_b = get_string_arg (node, 1);
    return expr_allocate_boolean (e, eval_OP_EQ_STRING (arg_a, arg_b));
  }

case OP_GE:
  {
    double arg_a = get_number_arg (node, 0);
    double arg_b = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_a) || !is_valid (arg_b);
    double result = force_sysmis ? SYSMIS : eval_OP_GE (arg_a, arg_b);
    return expr_allocate_boolean (e, result);
  }

case OP_GE_STRING:
  {
    struct substring arg_a = get_string_arg (node, 0);
    struct substring arg_b = get_string_arg (node, 1);
    return expr_allocate_boolean (e, eval_OP_GE_STRING (arg_a, arg_b));
  }

case OP_GT:
  {
    double arg_a = get_number_arg (node, 0);
    double arg_b = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_a) || !is_valid (arg_b);
    double result = force_sysmis ? SYSMIS : eval_OP_GT (arg_a, arg_b);
    return expr_allocate_boolean (e, result);
  }

case OP_GT_STRING:
  {
    struct substring arg_a = get_string_arg (node, 0);
    struct substring arg_b = get_string_arg (node, 1);
    return expr_allocate_boolean (e, eval_OP_GT_STRING (arg_a, arg_b));
  }

case OP_LE:
  {
    double arg_a = get_number_arg (node, 0);
    double arg_b = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_a) || !is_valid (arg_b);
    double result = force_sysmis ? SYSMIS : eval_OP_LE (arg_a, arg_b);
    return expr_allocate_boolean (e, result);
  }

case OP_LE_STRING:
  {
    struct substring arg_a = get_string_arg (node, 0);
    struct substring arg_b = get_string_arg (node, 1);
    return expr_allocate_boolean (e, eval_OP_LE_STRING (arg_a, arg_b));
  }

case OP_LT:
  {
    double arg_a = get_number_arg (node, 0);
    double arg_b = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_a) || !is_valid (arg_b);
    double result = force_sysmis ? SYSMIS : eval_OP_LT (arg_a, arg_b);
    return expr_allocate_boolean (e, result);
  }

case OP_LT_STRING:
  {
    struct substring arg_a = get_string_arg (node, 0);
    struct substring arg_b = get_string_arg (node, 1);
    return expr_allocate_boolean (e, eval_OP_LT_STRING (arg_a, arg_b));
  }

case OP_MUL:
  {
    double arg_a = get_number_arg (node, 0);
    double arg_b = get_number_arg (node, 1);
    return expr_allocate_number (e, eval_OP_MUL (arg_a, arg_b));
  }

case OP_NE:
  {
    double arg_a = get_number_arg (node, 0);
    double arg_b = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_a) || !is_valid (arg_b);
    double result = force_sysmis ? SYSMIS : eval_OP_NE (arg_a, arg_b);
    return expr_allocate_boolean (e, result);
  }

case OP_NEG:
  {
    double arg_x = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_x);
    double result = force_sysmis ? SYSMIS : eval_OP_NEG (arg_x);
    return expr_allocate_number (e, result);
  }

case OP_NE_STRING:
  {
    struct substring arg_a = get_string_arg (node, 0);
    struct substring arg_b = get_string_arg (node, 1);
    return expr_allocate_boolean (e, eval_OP_NE_STRING (arg_a, arg_b));
  }

case OP_NOT:
  {
    double arg_a = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_a);
    double result = force_sysmis ? SYSMIS : eval_OP_NOT (arg_a);
    return expr_allocate_boolean (e, result);
  }

case OP_NUM_SYS:
  NOT_REACHED ();

case OP_NUM_TO_BOOLEAN:
  {
    double arg_x = get_number_arg (node, 0);
    struct substring arg_op_name = get_string_arg (node, 1);
    bool force_sysmis = !is_valid (arg_x);
    double result = force_sysmis ? SYSMIS : eval_OP_NUM_TO_BOOLEAN (arg_x, arg_op_name);
    return expr_allocate_boolean (e, result);
  }

case OP_NUM_VAL:
  NOT_REACHED ();

case OP_NUM_VAR:
  NOT_REACHED ();

case OP_OR:
  {
    double arg_a = get_number_arg (node, 0);
    double arg_b = get_number_arg (node, 1);
    return expr_allocate_boolean (e, eval_OP_OR (arg_a, arg_b));
  }

case OP_POW:
  {
    double arg_a = get_number_arg (node, 0);
    double arg_b = get_number_arg (node, 1);
    return expr_allocate_number (e, eval_OP_POW (arg_a, arg_b));
  }

case OP_SQUARE:
  {
    double arg_x = get_number_arg (node, 0);
    bool force_sysmis = !is_valid (arg_x);
    double result = force_sysmis ? SYSMIS : eval_OP_SQUARE (arg_x);
    return expr_allocate_number (e, result);
  }

case OP_STR_VAR:
  NOT_REACHED ();

case OP_SUB:
  {
    double arg_a = get_number_arg (node, 0);
    double arg_b = get_number_arg (node, 1);
    bool force_sysmis = !is_valid (arg_a) || !is_valid (arg_b);
    double result = force_sysmis ? SYSMIS : eval_OP_SUB (arg_a, arg_b);
    return expr_allocate_number (e, result);
  }

case OP_VEC_ELEM_NUM:
  NOT_REACHED ();

case OP_VEC_ELEM_STR:
  NOT_REACHED ();


/*
   Local Variables:
   mode: c
   buffer-read-only: t
   End:
*/
