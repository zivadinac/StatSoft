/* src/language/expressions/evaluate.h
   Generated from ./src/language/expressions/operations.def by generate.pl.  
   Do not modify! */

#include "helpers.h"

static inline double 
eval_OP_ABS_n (double x)
{
  return fabs (x);
}

static inline double 
eval_OP_ACOS_n (double x)
{
  return acos (x);
}

static inline double 
eval_OP_ANY_nn (double x, double a[], size_t n)
{
  int sysmis = 0;
  size_t i;

  for (i = 0; i < n; i++)
    if (a[i] == x)
      return 1.;
    else if (a[i] == SYSMIS)
      sysmis = 1;

  return sysmis ? SYSMIS : 0.;
}

static inline double 
eval_OP_ANY_ss (struct substring x, struct substring a[], size_t n)
{
  size_t i;

  for (i = 0; i < n; i++)
    if (!compare_string_3way (&x, &a[i]))
      return 1.;
  return 0.;
}

static inline double 
eval_OP_ARCOS_n (double x)
{
  return acos (x);
}

static inline double 
eval_OP_ARSIN_n (double x)
{
  return asin (x);
}

static inline double 
eval_OP_ARTAN_n (double x)
{
  return atan (x);
}

static inline double 
eval_OP_ASIN_n (double x)
{
  return asin (x);
}

static inline double 
eval_OP_ATAN_n (double x)
{
  return atan (x);
}

static inline double 
eval_OP_CDF_BERNOULLI_nn (double k, double p)
{
  return k ? 1 : 1 - p;
}

static inline double 
eval_OP_CDF_BETA_nnn (double x, double a, double b)
{
  return gsl_cdf_beta_P (x, a, b);
}

static inline double 
eval_OP_CDF_BINOM_nnn (double k, double n, double p)
{
  return gsl_cdf_binomial_P (k, p, n);
}

static inline double 
eval_OP_CDF_BVNOR_nnn (double x0, double x1, double r)
{
  return cdf_bvnor (x0, x1, r);
}

static inline double 
eval_OP_CDF_CAUCHY_nnn (double x, double a, double b)
{
  return gsl_cdf_cauchy_P ((x - a) / b, 1);
}

static inline double 
eval_OP_CDF_CHISQ_nn (double x, double df)
{
  return gsl_cdf_chisq_P (x, df);
}

static inline double 
eval_OP_CDF_EXP_nn (double x, double a)
{
  return gsl_cdf_exponential_P (x, 1. / a);
}

static inline double 
eval_OP_CDF_F_nnn (double x, double df1, double df2)
{
  return gsl_cdf_fdist_P (x, df1, df2);
}

static inline double 
eval_OP_CDF_GAMMA_nnn (double x, double a, double b)
{
  return gsl_cdf_gamma_P (x, a, 1. / b);
}

static inline double 
eval_OP_CDF_GEOM_nn (double k, double p)
{
  return gsl_cdf_geometric_P (k, p);
}

static inline double 
eval_OP_CDF_HYPER_nnnn (double k, double a, double b, double c)
{
  return gsl_cdf_hypergeometric_P (k, c, a - c, b);
}

static inline double 
eval_OP_CDF_LAPLACE_nnn (double x, double a, double b)
{
  return gsl_cdf_laplace_P ((x - a) / b, 1);
}

static inline double 
eval_OP_CDF_LNORMAL_nnn (double x, double m, double s)
{
  return gsl_cdf_lognormal_P (x, log (m), s);
}

static inline double 
eval_OP_CDF_LOGISTIC_nnn (double x, double a, double b)
{
  return gsl_cdf_logistic_P ((x - a) / b, 1);
}

static inline double 
eval_OP_CDF_NEGBIN_nnn (double k, double n, double p)
{
  return gsl_cdf_negative_binomial_P (k, p, n);
}

static inline double 
eval_OP_CDF_NORMAL_nnn (double x, double u, double s)
{
  return gsl_cdf_gaussian_P (x - u, s);
}

static inline double 
eval_OP_CDF_PARETO_nnn (double x, double a, double b)
{
  return gsl_cdf_pareto_P (x, b, a);
}

static inline double 
eval_OP_CDF_POISSON_nn (double k, double mu)
{
  return gsl_cdf_poisson_P (k, mu);
}

static inline double 
eval_OP_CDF_RAYLEIGH_nn (double x, double sigma)
{
  return gsl_cdf_rayleigh_P (x, sigma);
}

static inline double 
eval_OP_CDF_T_nn (double x, double df)
{
  return gsl_cdf_tdist_P (x, df);
}

static inline double 
eval_OP_CDF_T1G_nnn (double x, double a, double b)
{
  return gsl_cdf_gumbel1_P (x, a, b);
}

static inline double 
eval_OP_CDF_T2G_nnn (double x, double a, double b)
{
  return gsl_cdf_gumbel2_P (x, a, b);
}

static inline double 
eval_OP_CDF_UNIFORM_nnn (double x, double a, double b)
{
  return gsl_cdf_flat_P (x, a, b);
}

static inline double 
eval_OP_CDF_WEIBULL_nnn (double x, double a, double b)
{
  return gsl_cdf_weibull_P (x, a, b);
}

static inline double 
eval_OP_CDFNORM_n (double x)
{
  return gsl_cdf_ugaussian_P (x);
}

static inline double 
eval_OP_CFVAR_n (double a[], size_t n)
{
  double mean, variance;

  moments_of_doubles (a, n, NULL, &mean, &variance, NULL, NULL);

  if (mean == SYSMIS || mean == 0 || variance == SYSMIS)
    return SYSMIS;
  else
    return sqrt (variance) / mean;
}

static inline struct substring 
eval_OP_CONCAT_s (struct substring a[], size_t n, struct expression *e)
{
  struct substring dst;
  size_t i;

  dst = alloc_string (e, MAX_STRING);
  dst.length = 0;
  for (i = 0; i < n; i++)
    {
      struct substring *src = &a[i];
      size_t copy_len;

      copy_len = src->length;
      if (dst.length + copy_len > MAX_STRING)
        copy_len = MAX_STRING - dst.length;
      memcpy (&dst.string[dst.length], src->string, copy_len);
      dst.length += copy_len;
    }

  return dst;
}

static inline double 
eval_OP_COS_n (double x)
{
  return cos (x);
}

static inline double 
eval_OP_CTIME_DAYS_n (double time)
{
  return time / DAY_S;
}

static inline double 
eval_OP_CTIME_HOURS_n (double time)
{
  return time / H_S;
}

static inline double 
eval_OP_CTIME_MINUTES_n (double time)
{
  return time / MIN_S;
}

static inline double 
eval_OP_CTIME_SECONDS_n (double time)
{
  return time;
}

static inline double 
eval_OP_DATE_DMY_nnn (double d, double m, double y)
{
  return expr_ymd_to_date (y, m, d);
}

static inline double 
eval_OP_DATE_MDY_nnn (double m, double d, double y)
{
  return expr_ymd_to_date (y, m, d);
}

static inline double 
eval_OP_DATE_MOYR_nn (double m, double y)
{
  return expr_ymd_to_date (y, m, 1);
}

static inline double 
eval_OP_DATE_QYR_nn (double q, double y)
{
  if (q < 1.0 || q > 4.0 || q != (int) q)
    {
      msg (SW, _("The first argument to DATE.QYR must be 1, 2, 3, or 4."));
      return SYSMIS;
    }
   return expr_ymd_to_date (y, q * 3 - 2, 1);
}

static inline double 
eval_OP_DATE_WKYR_nn (double w, double y)
{
  return expr_wkyr_to_date (w, y);
}

static inline double 
eval_OP_DATE_YRDAY_nn (double y, double yday)
{
  return expr_yrday_to_date (y, yday);
}

static inline double 
eval_OP_DATEDIFF_nns (double date2, double date1, struct substring unit)
{
  return expr_date_difference (date1, date2, unit);
}

static inline double 
eval_OP_DATESUM_nns (double date, double quantity, struct substring unit)
{
  return expr_date_sum (date, quantity, unit, ss_cstr ("closest"));
}

static inline double 
eval_OP_DATESUM_nnss (double date, double quantity, struct substring unit, struct substring method)
{
  return expr_date_sum (date, quantity, unit, method);
}

static inline double 
eval_OP_EXP_n (double x)
{
  return check_errno (exp (x));
}

static inline double 
eval_OP_IDF_BETA_nnn (double P, double a, double b)
{
  return gsl_cdf_beta_Pinv (P, a, b);
}

static inline double 
eval_OP_IDF_CAUCHY_nnn (double P, double a, double b)
{
  return a + b * gsl_cdf_cauchy_Pinv (P, 1);
}

static inline double 
eval_OP_IDF_CHISQ_nn (double P, double df)
{
  return gsl_cdf_chisq_Pinv (P, df);
}

static inline double 
eval_OP_IDF_EXP_nn (double P, double a)
{
  return gsl_cdf_exponential_Pinv (P, 1. / a);
}

static inline double 
eval_OP_IDF_F_nnn (double P, double df1, double df2)
{
  return idf_fdist (P, df1, df2);
}

static inline double 
eval_OP_IDF_GAMMA_nnn (double P, double a, double b)
{
  return gsl_cdf_gamma_Pinv (P, a, 1. / b);
}

static inline double 
eval_OP_IDF_LAPLACE_nnn (double P, double a, double b)
{
  return a + b * gsl_cdf_laplace_Pinv (P, 1);
}

static inline double 
eval_OP_IDF_LNORMAL_nnn (double P, double m, double s)
{
  return gsl_cdf_lognormal_Pinv (P, log (m), s);
}

static inline double 
eval_OP_IDF_LOGISTIC_nnn (double P, double a, double b)
{
  return a + b * gsl_cdf_logistic_Pinv (P, 1);
}

static inline double 
eval_OP_IDF_NORMAL_nnn (double P, double u, double s)
{
  return u + gsl_cdf_gaussian_Pinv (P, s);
}

static inline double 
eval_OP_IDF_PARETO_nnn (double P, double a, double b)
{
  return gsl_cdf_pareto_Pinv (P, b, a);
}

static inline double 
eval_OP_IDF_RAYLEIGH_nn (double P, double sigma)
{
  return gsl_cdf_rayleigh_Pinv (P, sigma);
}

static inline double 
eval_OP_IDF_T_nn (double P, double df)
{
  return gsl_cdf_tdist_Pinv (P, df);
}

static inline double 
eval_OP_IDF_T1G_nnn (double P, double a, double b)
{
  return gsl_cdf_gumbel1_P (P, a, b);
}

static inline double 
eval_OP_IDF_T2G_nnn (double P, double a, double b)
{
  return gsl_cdf_gumbel2_P (P, a, b);
}

static inline double 
eval_OP_IDF_UNIFORM_nnn (double P, double a, double b)
{
  return gsl_cdf_flat_Pinv (P, a, b);
}

static inline double 
eval_OP_IDF_WEIBULL_nnn (double P, double a, double b)
{
  return gsl_cdf_weibull_Pinv (P, a, b);
}

static inline double 
eval_OP_INDEX_ss (struct substring haystack, struct substring needle)
{
  if (needle.length == 0)
    return SYSMIS;
  else
    {
      int limit = haystack.length - needle.length + 1;
      int i;
      for (i = 1; i <= limit; i++)
        if (!memcmp (&haystack.string[i - 1], needle.string, needle.length))
          return i;
      return 0;
    }
}

static inline double 
eval_OP_INDEX_ssn (struct substring haystack, struct substring needles, double needle_len_d)
{
  if (needle_len_d <= INT_MIN || needle_len_d >= INT_MAX
      || (int) needle_len_d != needle_len_d
      || needles.length == 0)
    return SYSMIS;
  else
    {
      int needle_len = needle_len_d;
      if (needle_len < 0 || needle_len > needles.length
          || needles.length % needle_len != 0)
        return SYSMIS;
      else
        {
          int limit = haystack.length - needle_len + 1;
          int i, j;
          for (i = 1; i <= limit; i++)
            for (j = 0; j < needles.length; j += needle_len)
              if (!memcmp (&haystack.string[i - 1], &needles.string[j],
                           needle_len))
                return i;
          return 0;
        }
    }
}

static inline double 
eval_OP_LAG_Vn (const struct variable *v, struct dataset *ds)
{
  const struct ccase *c = lagged_case (ds, 1);
  if (c != NULL)
    {
      double x = case_num (c, v);
      return !var_is_num_missing (v, x, MV_USER) ? x : SYSMIS;
    }
  else
    return SYSMIS;
}

static inline double 
eval_OP_LAG_Vnn (const struct variable *v, int n_before, struct dataset *ds)
{
  const struct ccase *c = lagged_case (ds, n_before);
  if (c != NULL)
    {
      double x = case_num (c, v);
      return !var_is_num_missing (v, x, MV_USER) ? x : SYSMIS;
    }
  else
    return SYSMIS;
}

static inline struct substring 
eval_OP_LAG_Vs (const struct variable *v, struct expression *e, struct dataset *ds)
{
  const struct ccase *c = lagged_case (ds, 1);
  if (c != NULL)
    return copy_string (e, CHAR_CAST_BUG (char *, case_str (c, v)),
                        var_get_width (v));
  else
    return empty_string;
}

static inline struct substring 
eval_OP_LAG_Vsn (const struct variable *v, int n_before, struct expression *e, struct dataset *ds)
{
  const struct ccase *c = lagged_case (ds, n_before);
  if (c != NULL)
    return copy_string (e, CHAR_CAST_BUG (char *, case_str (c, v)),
                        var_get_width (v));
  else
    return empty_string;
}

static inline double 
eval_OP_LENGTH_s (struct substring s)
{
  return s.length;
}

static inline double 
eval_OP_LG10_n (double x)
{
  return check_errno (log10 (x));
}

static inline double 
eval_OP_LN_n (double x)
{
  return check_errno (log (x));
}

static inline double 
eval_OP_LNGAMMA_n (double x)
{
  return gsl_sf_lngamma (x);
}

static inline struct substring 
eval_OP_LOWER_s (struct substring s)
{
  int i;

  for (i = 0; i < s.length; i++)
    s.string[i] = tolower ((unsigned char) s.string[i]);
  return s;
}

static inline struct substring 
eval_OP_LPAD_sn (struct substring s, double n, struct expression *e)
{
  if (n < 0 || n > MAX_STRING || (int) n != n)
    return empty_string;
  else if (s.length >= n)
    return s;
  else
    {
      struct substring t = alloc_string (e, n);
      memset (t.string, ' ', n - s.length);
      memcpy (&t.string[(int) n - s.length], s.string, s.length);
      return t;
    }
}

static inline struct substring 
eval_OP_LPAD_sns (struct substring s, double n, struct substring c, struct expression *e)
{
  if (n < 0 || n > MAX_STRING || (int) n != n || c.length != 1)
    return empty_string;
  else if (s.length >= n)
    return s;
  else
    {
      struct substring t = alloc_string (e, n);
      memset (t.string, c.string[0], n - s.length);
      memcpy (&t.string[(int) n - s.length], s.string, s.length);
      return t;
    }
}

static inline struct substring 
eval_OP_LTRIM_s (struct substring s)
{
  while (s.length > 0 && s.string[0] == ' ') 
    {
      s.length--;
      s.string++;
    }
  return s;
}

static inline struct substring 
eval_OP_LTRIM_ss (struct substring s, struct substring c)
{
  if (c.length == 1)
    {
      while (s.length > 0 && s.string[0] == c.string[0]) 
        {
          s.length--;
          s.string++;
        }
      return s;
    }
  else
    return empty_string;
}

static inline double 
eval_OP_MAX_n (double a[], size_t n)
{
  double max;
  size_t i;

  max = -DBL_MAX;
  for (i = 0; i < n; i++)
    if (a[i] != SYSMIS && a[i] > max)
      max = a[i];
  return max;
}

static inline struct substring 
eval_OP_MAX_s (struct substring a[], size_t n)
{
  struct substring *max;
  size_t i;

  max = &a[0];
  for (i = 1; i < n; i++)
    if (compare_string_3way (&a[i], max) > 0)
      max = &a[i];
  return *max;
}

static inline double 
eval_OP_MBLEN_BYTE_sn (struct substring s, double idx)
{
  if (idx < 0 || idx >= s.length || (int) idx != idx)
    return SYSMIS;
  else
    return 1;
}

static inline double 
eval_OP_MEAN_n (double a[], size_t n)
{
  double mean;
  moments_of_doubles (a, n, NULL, &mean, NULL, NULL, NULL);
  return mean;
}

static inline double 
eval_OP_MEDIAN_n (double a[], size_t n)
{
  return median (a, n);
}

static inline double 
eval_OP_MIN_n (double a[], size_t n)
{
  double min;
  size_t i;

  min = DBL_MAX;
  for (i = 0; i < n; i++)
    if (a[i] != SYSMIS && a[i] < min)
      min = a[i];
  return min;
}

static inline struct substring 
eval_OP_MIN_s (struct substring a[], size_t n)
{
  struct substring *min;
  size_t i;

  min = &a[0];
  for (i = 1; i < n; i++)
    if (compare_string_3way (&a[i], min) < 0)
      min = &a[i];
  return *min;
}

static inline double 
eval_OP_MISSING_n (double x)
{
  return x == SYSMIS || !finite (x);
}

static inline double 
eval_OP_MOD_nn (double n, double d)
{
  if (d != SYSMIS)
    return n != SYSMIS ? fmod (n, d) : SYSMIS;
  else
    return n != 0. ? SYSMIS : 0.;
}

static inline double 
eval_OP_MOD10_n (double x)
{
  return fmod (x, 10);
}

static inline double 
eval_OP_NCDF_BETA_nnnn (double x, double a, double b, double lambda)
{
  return ncdf_beta (x, a, b, lambda);
}

static inline double 
eval_OP_NMISS_n (double a[], size_t n)
{
  size_t i;
  size_t missing_cnt = 0;

  for (i = 0; i < n; i++)
    missing_cnt += a[i] == SYSMIS;
  return missing_cnt;
}

static inline double 
eval_OP_NORMAL_n (double s)
{
  return gsl_ran_gaussian (get_rng (), s);
}

static inline double 
eval_OP_NPDF_BETA_nnnn (double x, double a, double b, double lambda)
{
  return npdf_beta (x, a, b, lambda);
}

static inline double 
eval_OP_NUMBER_sf (struct substring s, const struct fmt_spec *f)
{
  union value out;
  char *error;

  if (s.length > f->w)
    s.length = f->w;
  error = data_in (s, C_ENCODING, f->type, &out, 0, NULL);
  if (error == NULL)
    data_in_imply_decimals (s, C_ENCODING, f->type, f->d, &out);
  else
    {
      msg (SE, "Cannot parse `%.*s' as format %s: %s",
           (int) s.length, s.string, fmt_name (f->type), error);
      free (error);
    }
  return out.f;
}

static inline double 
eval_OP_NVALID_n (double a[], size_t n)
{
  size_t i;
  size_t valid_cnt = 0;

  for (i = 0; i < n; i++)
    valid_cnt += a[i] != SYSMIS;
  return valid_cnt;
}

static inline double 
eval_OP_PDF_BERNOULLI_nn (double k, double p)
{
  return gsl_ran_bernoulli_pdf (k, p);
}

static inline double 
eval_OP_PDF_BETA_nnn (double x, double a, double b)
{
  return gsl_ran_beta_pdf (x, a, b);
}

static inline double 
eval_OP_PDF_BINOM_nnn (double k, double n, double p)
{
  return gsl_ran_binomial_pdf (k, p, n);
}

static inline double 
eval_OP_PDF_BVNOR_nnn (double x0, double x1, double r)
{
  return gsl_ran_bivariate_gaussian_pdf (x0, x1, 1, 1, r);
}

static inline double 
eval_OP_PDF_CAUCHY_nnn (double x, double a, double b)
{
  return gsl_ran_cauchy_pdf ((x - a) / b, 1) / b;
}

static inline double 
eval_OP_PDF_CHISQ_nn (double x, double df)
{
  return gsl_ran_chisq_pdf (x, df);
}

static inline double 
eval_OP_PDF_EXP_nn (double x, double a)
{
  return gsl_ran_exponential_pdf (x, 1. / a);
}

static inline double 
eval_OP_PDF_F_nnn (double x, double df1, double df2)
{
  return gsl_ran_fdist_pdf (x, df1, df2);
}

static inline double 
eval_OP_PDF_GAMMA_nnn (double x, double a, double b)
{
  return gsl_ran_gamma_pdf (x, a, 1. / b);
}

static inline double 
eval_OP_PDF_GEOM_nn (double k, double p)
{
  return gsl_ran_geometric_pdf (k, p);
}

static inline double 
eval_OP_PDF_HYPER_nnnn (double k, double a, double b, double c)
{
  return gsl_ran_hypergeometric_pdf (k, c, a - c, b);
}

static inline double 
eval_OP_PDF_LANDAU_n (double x)
{
  return gsl_ran_landau_pdf (x);
}

static inline double 
eval_OP_PDF_LAPLACE_nnn (double x, double a, double b)
{
  return gsl_ran_laplace_pdf ((x - a) / b, 1) / b;
}

static inline double 
eval_OP_PDF_LNORMAL_nnn (double x, double m, double s)
{
  return gsl_ran_lognormal_pdf (x, log (m), s);
}

static inline double 
eval_OP_PDF_LOG_nn (double k, double p)
{
  return gsl_ran_logarithmic_pdf (k, p);
}

static inline double 
eval_OP_PDF_LOGISTIC_nnn (double x, double a, double b)
{
  return gsl_ran_logistic_pdf ((x - a) / b, 1) / b;
}

static inline double 
eval_OP_PDF_NEGBIN_nnn (double k, double n, double p)
{
  return gsl_ran_negative_binomial_pdf (k, p, n);
}

static inline double 
eval_OP_PDF_NORMAL_nnn (double x, double u, double s)
{
  return gsl_ran_gaussian_pdf ((x - u) / s, 1) / s;
}

static inline double 
eval_OP_PDF_NTAIL_nnn (double x, double a, double sigma)
{
  return gsl_ran_gaussian_tail_pdf (x, a, sigma);
}

static inline double 
eval_OP_PDF_PARETO_nnn (double x, double a, double b)
{
  return gsl_ran_pareto_pdf (x, b, a);
}

static inline double 
eval_OP_PDF_POISSON_nn (double k, double mu)
{
  return gsl_ran_poisson_pdf (k, mu);
}

static inline double 
eval_OP_PDF_RAYLEIGH_nn (double x, double sigma)
{
  return gsl_ran_rayleigh_pdf (x, sigma);
}

static inline double 
eval_OP_PDF_RTAIL_nnn (double x, double a, double sigma)
{
  return gsl_ran_rayleigh_tail_pdf (x, a, sigma);
}

static inline double 
eval_OP_PDF_T_nn (double x, double df)
{
  return gsl_ran_tdist_pdf (x, df);
}

static inline double 
eval_OP_PDF_T1G_nnn (double x, double a, double b)
{
  return gsl_ran_gumbel1_pdf (x, a, b);
}

static inline double 
eval_OP_PDF_T2G_nnn (double x, double a, double b)
{
  return gsl_ran_gumbel2_pdf (x, a, b);
}

static inline double 
eval_OP_PDF_UNIFORM_nnn (double x, double a, double b)
{
  return gsl_ran_flat_pdf (x, a, b);
}

static inline double 
eval_OP_PDF_WEIBULL_nnn (double x, double a, double b)
{
  return gsl_ran_weibull_pdf (x, a, b);
}

static inline double 
eval_OP_PDF_XPOWER_nnn (double x, double a, double b)
{
  return gsl_ran_exppow_pdf (x, a, b);
}

static inline double 
eval_OP_PROBIT_n (double P)
{
  return gsl_cdf_ugaussian_Pinv (P);
}

static inline double 
eval_OP_RANGE_nn (double x, double a[], size_t n)
{
  size_t i;
  int sysmis = 0;

  for (i = 0; i < n; i++)
    {
      double w = a[2 * i];
      double y = a[2 * i + 1];
      if (w != SYSMIS && y != SYSMIS)
        {
          if (w <= x && x <= y)
            return 1.0;
        }
      else
        sysmis = 1;
    }
  return sysmis ? SYSMIS : 0.;
}

static inline double 
eval_OP_RANGE_ss (struct substring x, struct substring a[], size_t n)
{
  int i;

  for (i = 0; i < n; i++)
    {
      struct substring *w = &a[2 * i];
      struct substring *y = &a[2 * i + 1];
      if (compare_string_3way (w, &x) <= 0 && compare_string_3way (&x, y) <= 0)
        return 1.;
    }
  return 0.;
}

static inline struct substring 
eval_OP_REPLACE_sss (struct substring haystack, struct substring needle, struct substring replacement, struct expression *e)
{
  return replace_string (e, haystack, needle, replacement, DBL_MAX);
}

static inline struct substring 
eval_OP_REPLACE_sssn (struct substring haystack, struct substring needle, struct substring replacement, double n, struct expression *e)
{
  return replace_string (e, haystack, needle, replacement, n);
}

static inline double 
eval_OP_RINDEX_ss (struct substring haystack, struct substring needle)
{
  if (needle.length == 0)
    return SYSMIS;
  else
    {
      int limit = haystack.length - needle.length + 1;
      int i;
      for (i = limit; i >= 1; i--)
        if (!memcmp (&haystack.string[i - 1], needle.string, needle.length))
          return i;
      return 0;
    }
}

static inline double 
eval_OP_RINDEX_ssn (struct substring haystack, struct substring needles, double needle_len_d)
{
  if (needle_len_d <= 0 || needle_len_d >= INT_MAX
      || (int) needle_len_d != needle_len_d
      || needles.length == 0)
    return SYSMIS;
  else
    {
      int needle_len = needle_len_d;
      if (needle_len < 0 || needle_len > needles.length
          || needles.length % needle_len != 0)
        return SYSMIS;
      else
        {
          int limit = haystack.length - needle_len + 1;
          int i, j;
          for (i = limit; i >= 1; i--)
            for (j = 0; j < needles.length; j += needle_len)
              if (!memcmp (&haystack.string[i - 1],
                           &needles.string[j], needle_len))
                return i;
          return 0;
        }
    }
}

static inline double 
eval_OP_RND_n (double x)
{
  return round_nearest (x, 1, 0);
}

static inline double 
eval_OP_RND_nn (double x, double mult)
{
  return round_nearest (x, mult, 0);
}

static inline double 
eval_OP_RND_nnn (double x, double mult, double fuzzbits)
{
  return round_nearest (x, mult, fuzzbits);
}

static inline struct substring 
eval_OP_RPAD_sn (struct substring s, double n, struct expression *e)
{
  if (n < 0 || n > MAX_STRING || (int) n != n)
    return empty_string;
  else if (s.length >= n)
    return s;
  else
    {
      struct substring t = alloc_string (e, n);
      memcpy (t.string, s.string, s.length);
      memset (&t.string[s.length], ' ', n - s.length);
      return t;
    }
}

static inline struct substring 
eval_OP_RPAD_sns (struct substring s, double n, struct substring c, struct expression *e)
{
  if (n < 0 || n > MAX_STRING || (int) n != n || c.length != 1)
    return empty_string;
  else if (s.length >= n)
    return s;
  else
    {
      struct substring t = alloc_string (e, n);
      memcpy (t.string, s.string, s.length);
      memset (&t.string[s.length], c.string[0], n - s.length);
      return t;
    }
}

static inline struct substring 
eval_OP_RTRIM_s (struct substring s)
{
  while (s.length > 0 && s.string[s.length - 1] == ' ')
    s.length--;
  return s;
}

static inline struct substring 
eval_OP_RTRIM_ss (struct substring s, struct substring c)
{
  if (c.length == 1)
    {
      while (s.length > 0 && s.string[s.length - 1] == c.string[0])
        s.length--;
      return s;
    }
  else
    return empty_string;
}

static inline double 
eval_OP_RV_BERNOULLI_n (double p)
{
  return gsl_ran_bernoulli (get_rng (), p);
}

static inline double 
eval_OP_RV_BETA_nn (double a, double b)
{
  return gsl_ran_beta (get_rng (), a, b);
}

static inline double 
eval_OP_RV_BINOM_nn (double p, double n)
{
  return gsl_ran_binomial (get_rng (), p, n);
}

static inline double 
eval_OP_RV_CAUCHY_nn (double a, double b)
{
  return a + b * gsl_ran_cauchy (get_rng (), 1);
}

static inline double 
eval_OP_RV_CHISQ_n (double df)
{
  return gsl_ran_chisq (get_rng (), df);
}

static inline double 
eval_OP_RV_EXP_n (double a)
{
  return gsl_ran_exponential (get_rng (), 1. / a);
}

static inline double 
eval_OP_RV_F_nn (double df1, double df2)
{
  return gsl_ran_fdist (get_rng (), df1, df2);
}

static inline double 
eval_OP_RV_GAMMA_nn (double a, double b)
{
  return gsl_ran_gamma (get_rng (), a, 1. / b);
}

static inline double 
eval_OP_RV_GEOM_n (double p)
{
  return gsl_ran_geometric (get_rng (), p);
}

static inline double 
eval_OP_RV_HYPER_nnn (double a, double b, double c)
{
  return gsl_ran_hypergeometric (get_rng (), c, a - c, b);
}

static inline double 
eval_OP_RV_LANDAU_ (void)
{
  return gsl_ran_landau (get_rng ());
}

static inline double 
eval_OP_RV_LAPLACE_nn (double a, double b)
{
  return a + b * gsl_ran_laplace (get_rng (), 1);
}

static inline double 
eval_OP_RV_LEVY_nn (double c, double alpha)
{
  return gsl_ran_levy (get_rng (), c, alpha);
}

static inline double 
eval_OP_RV_LNORMAL_nn (double m, double s)
{
  return gsl_ran_lognormal (get_rng (), log (m), s);
}

static inline double 
eval_OP_RV_LOG_n (double p)
{
  return gsl_ran_logarithmic (get_rng (), p);
}

static inline double 
eval_OP_RV_LOGISTIC_nn (double a, double b)
{
  return a + b * gsl_ran_logistic (get_rng (), 1);
}

static inline double 
eval_OP_RV_LVSKEW_nnn (double c, double alpha, double beta)
{
  return gsl_ran_levy_skew (get_rng (), c, alpha, beta);
}

static inline double 
eval_OP_RV_NEGBIN_nn (double n, double p)
{
  return gsl_ran_negative_binomial (get_rng (), p, n);
}

static inline double 
eval_OP_RV_NORMAL_nn (double u, double s)
{
  return u + gsl_ran_gaussian (get_rng (), s);
}

static inline double 
eval_OP_RV_NTAIL_nn (double a, double sigma)
{
  return gsl_ran_gaussian_tail (get_rng (), a, sigma);
}

static inline double 
eval_OP_RV_PARETO_nn (double a, double b)
{
  return gsl_ran_pareto (get_rng (), b, a);
}

static inline double 
eval_OP_RV_POISSON_n (double mu)
{
  return gsl_ran_poisson (get_rng (), mu);
}

static inline double 
eval_OP_RV_RAYLEIGH_n (double sigma)
{
  return gsl_ran_rayleigh (get_rng (), sigma);
}

static inline double 
eval_OP_RV_RTAIL_nn (double a, double sigma)
{
  return gsl_ran_rayleigh_tail (get_rng (), a, sigma);
}

static inline double 
eval_OP_RV_T_n (double df)
{
  return gsl_ran_tdist (get_rng (), df);
}

static inline double 
eval_OP_RV_T1G_nn (double a, double b)
{
  return gsl_ran_gumbel1 (get_rng (), a, b);
}

static inline double 
eval_OP_RV_T2G_nn (double a, double b)
{
  return gsl_ran_gumbel2 (get_rng (), a, b);
}

static inline double 
eval_OP_RV_UNIFORM_nn (double a, double b)
{
  return gsl_ran_flat (get_rng (), a, b);
}

static inline double 
eval_OP_RV_WEIBULL_nn (double a, double b)
{
  return gsl_ran_weibull (get_rng (), a, b);
}

static inline double 
eval_OP_RV_XPOWER_nn (double a, double b)
{
  return gsl_ran_exppow (get_rng (), a, b);
}

static inline double 
eval_OP_SD_n (double a[], size_t n)
{
  double variance;
  moments_of_doubles (a, n, NULL, NULL, &variance, NULL, NULL);
  return sqrt (variance);
}

static inline double 
eval_OP_SIG_CHISQ_nn (double x, double df)
{
  return gsl_cdf_chisq_Q (x, df);
}

static inline double 
eval_OP_SIG_F_nnn (double x, double df1, double df2)
{
  return gsl_cdf_fdist_Q (x, df1, df2);
}

static inline double 
eval_OP_SIN_n (double x)
{
  return sin (x);
}

static inline double 
eval_OP_SQRT_n (double x)
{
  return sqrt (x);
}

static inline struct substring 
eval_OP_STRING_nf (double x, const struct fmt_spec *f, struct expression *e)
{
  union value v;
  struct substring dst;
  char *s;

  v.f = x;

  assert (!fmt_is_string (f->type));
  s = data_out (&v, C_ENCODING, f);
  dst = alloc_string (e, strlen (s));
  strcpy (dst.string, s);
  free (s);
  return dst;
}

static inline struct substring 
eval_OP_STRUNC_sn (struct substring s, double n)
{
  if (n < 1 || n == SYSMIS)
    return empty_string;

  if (n < s.length)
    s.length = n;
  while (s.length > 0 && s.string[s.length - 1] == ' ')
    s.length--;
  return s;
}

static inline struct substring 
eval_OP_SUBSTR_sn (struct substring s, double ofs, struct expression *e)
{
  if (ofs >= 1 && ofs <= s.length && (int) ofs == ofs)
    return copy_string (e, &s.string[(int) ofs - 1], s.length - ofs + 1);
  else
    return empty_string;
}

static inline struct substring 
eval_OP_SUBSTR_snn (struct substring s, double ofs, double cnt, struct expression *e)
{
  if (ofs >= 1 && ofs <= s.length && (int) ofs == ofs
      && cnt >= 1 && cnt <= INT_MAX && (int) cnt == cnt)
    {
      int cnt_max = s.length - (int) ofs + 1;
      return copy_string (e, &s.string[(int) ofs - 1],
                          cnt <= cnt_max ? cnt : cnt_max);
    }
  else
    return empty_string;
}

static inline double 
eval_OP_SUM_n (double a[], size_t n)
{
  double sum;
  size_t i;

  sum = 0.;
  for (i = 0; i < n; i++)
    if (a[i] != SYSMIS)
      sum += a[i];
  return sum;
}

static inline double 
eval_OP_SYSMIS_Vn (const struct variable *v, const struct ccase *c)
{
  return case_num (c, v) == SYSMIS;
}

static inline double 
eval_OP_SYSMIS_n (double x)
{
  return x == SYSMIS || !finite (x);
}

static inline double 
eval_OP_TAN_n (double x)
{
  return check_errno (tan (x));
}

static inline double 
eval_OP_TIME_DAYS_n (double days)
{
  return days * DAY_S;
}

static inline double 
eval_OP_TIME_HMS_nnn (double h, double m, double s)
{
  if ((h > 0. || m > 0. || s > 0.) && (h < 0. || m < 0. || s < 0.))
    {
      msg (SW, _("TIME.HMS cannot mix positive and negative arguments."));
      return SYSMIS;
    }
  else
    return H_S * h + MIN_S * m + s;
}

static inline double 
eval_OP_TRUNC_n (double x)
{
  return round_zero (x, 1, 0);
}

static inline double 
eval_OP_TRUNC_nn (double x, double mult)
{
  return round_zero (x, mult, 0);
}

static inline double 
eval_OP_TRUNC_nnn (double x, double mult, double fuzzbits)
{
  return round_zero (x, mult, fuzzbits);
}

static inline double 
eval_OP_UNIFORM_n (double b)
{
  return gsl_ran_flat (get_rng (), 0, b);
}

static inline struct substring 
eval_OP_UPCASE_s (struct substring s)
{
  int i;

  for (i = 0; i < s.length; i++)
    s.string[i] = toupper ((unsigned char) s.string[i]);
  return s;
}

static inline double 
eval_OP_VALUE_Vn (const struct variable *v, const struct ccase *c)
{
  return case_num (c, v);
}

static inline struct substring 
eval_OP_VALUELABEL_V (const struct variable *v, struct expression *e, const struct ccase *c)
{
  const char *label = var_lookup_value_label (v, case_data (c, v));
  if (label != NULL)
    return copy_string (e, label, strlen (label));
  else
    return empty_string;
}

static inline double 
eval_OP_VARIANCE_n (double a[], size_t n)
{
  double variance;
  moments_of_doubles (a, n, NULL, NULL, &variance, NULL, NULL);
  return variance;
}

static inline double 
eval_OP_XDATE_DATE_n (double date)
{
  return floor (date / DAY_S) * DAY_S;
}

static inline double 
eval_OP_XDATE_HOUR_n (double date)
{
  return fmod (floor (date / H_S), DAY_H);
}

static inline double 
eval_OP_XDATE_JDAY_n (double date)
{
  return calendar_offset_to_yday (date / DAY_S);
}

static inline double 
eval_OP_XDATE_MDAY_n (double date)
{
  return calendar_offset_to_mday (date / DAY_S);
}

static inline double 
eval_OP_XDATE_MINUTE_n (double date)
{
  return fmod (floor (date / H_MIN), H_MIN);
}

static inline double 
eval_OP_XDATE_MONTH_n (double date)
{
  return calendar_offset_to_month (date / DAY_S);
}

static inline double 
eval_OP_XDATE_QUARTER_n (double date)
{
  return (calendar_offset_to_month (date / DAY_S) - 1) / 3 + 1;
}

static inline double 
eval_OP_XDATE_SECOND_n (double date)
{
  return fmod (date, MIN_S);
}

static inline double 
eval_OP_XDATE_TDAY_n (double date)
{
  return floor (date / DAY_S);
}

static inline double 
eval_OP_XDATE_TIME_n (double date)
{
  return fmod (date, DAY_S);
}

static inline double 
eval_OP_XDATE_WEEK_n (double date)
{
  return (calendar_offset_to_yday (date / DAY_S) - 1) / 7 + 1;
}

static inline double 
eval_OP_XDATE_WKDAY_n (double date)
{
  return calendar_offset_to_wday (date / DAY_S);
}

static inline double 
eval_OP_XDATE_YEAR_n (double date)
{
  return calendar_offset_to_year (date / DAY_S);
}

static inline double 
eval_OP_YRMODA_nnn (double y, double m, double d)
{
  return expr_yrmoda (y, m, d);
}

static inline double 
eval_OP_ADD (double a, double b)
{
  return a + b;
}

static inline double 
eval_OP_AND (double a, double b)
{
  return (a == 0. ? 0.
   : b == 0. ? 0.
   : b == SYSMIS ? SYSMIS
   : a);
}

static inline double 
eval_OP_BOOLEAN_TO_NUM (double x)
{
  return x;
}

static inline double 
eval_OP_CASENUM (size_t idx)
{
  return idx;
}

static inline double 
eval_OP_DIV (double a, double b)
{
  return (a == 0. ? 0.
   : a == SYSMIS || b == SYSMIS ? SYSMIS
   : a / b);
}

static inline double 
eval_OP_EQ (double a, double b)
{
  return a == b;
}

static inline double 
eval_OP_EQ_STRING (struct substring a, struct substring b)
{
  return compare_string_3way (&a, &b) == 0;
}

static inline double 
eval_OP_GE (double a, double b)
{
  return a >= b;
}

static inline double 
eval_OP_GE_STRING (struct substring a, struct substring b)
{
  return compare_string_3way (&a, &b) >= 0;
}

static inline double 
eval_OP_GT (double a, double b)
{
  return a > b;
}

static inline double 
eval_OP_GT_STRING (struct substring a, struct substring b)
{
  return compare_string_3way (&a, &b) > 0;
}

static inline double 
eval_OP_LE (double a, double b)
{
  return a <= b;
}

static inline double 
eval_OP_LE_STRING (struct substring a, struct substring b)
{
  return compare_string_3way (&a, &b) <= 0;
}

static inline double 
eval_OP_LT (double a, double b)
{
  return a < b;
}

static inline double 
eval_OP_LT_STRING (struct substring a, struct substring b)
{
  return compare_string_3way (&a, &b) < 0;
}

static inline double 
eval_OP_MUL (double a, double b)
{
  return (a == 0. || b == 0. ? 0.
   : a == SYSMIS || b == SYSMIS ? SYSMIS
   : a * b);
}

static inline double 
eval_OP_NE (double a, double b)
{
  return a != b;
}

static inline double 
eval_OP_NEG (double x)
{
  return -x;
}

static inline double 
eval_OP_NE_STRING (struct substring a, struct substring b)
{
  return compare_string_3way (&a, &b) != 0;
}

static inline double 
eval_OP_NOT (double a)
{
  return (a == 0. ? 1.
   : a == 1. ? 0.
   : SYSMIS);
}

static inline double 
eval_OP_NUM_SYS (const struct ccase *c, const struct variable *v)
{
  return case_num (c, v) == SYSMIS;
}

static inline double 
eval_OP_NUM_TO_BOOLEAN (double x, struct substring op_name)
{
  if (x == 0. || x == 1. || x == SYSMIS)
    return x;

  if (!ss_is_empty (op_name))
    msg (SE, _("An operand of the %.*s operator was found to have a value "
               "other than 0 (false), 1 (true), or the system-missing "
               "value.  The result was forced to 0."),
         (int) op_name.length, op_name.string);
  else
    msg (SE, _("A logical expression was found to have a value other than 0 "
               "(false), 1 (true), or the system-missing value.  The result "
               "was forced to 0."));
  return 0.;
}

static inline double 
eval_OP_NUM_VAL (const struct ccase *c, const struct variable *v)
{
  return case_num (c, v);
}

static inline double 
eval_OP_NUM_VAR (const struct ccase *c, const struct variable *v)
{
  double d = case_num (c, v);
  return !var_is_num_missing (v, d, MV_USER) ? d : SYSMIS;
}

static inline double 
eval_OP_OR (double a, double b)
{
  return (a == 1. ? 1.
   : b == 1. ? 1.
   : b == SYSMIS ? SYSMIS
   : a);
}

static inline double 
eval_OP_POW (double a, double b)
{
  return (a == SYSMIS ? (b == 0. ? 1. : a)
   : b == SYSMIS ? (a == 0. ? 0. : SYSMIS)
   : a == 0. && b <= 0. ? SYSMIS
   : pow (a, b));
}

static inline double 
eval_OP_SQUARE (double x)
{
  return x * x;
}

static inline struct substring 
eval_OP_STR_VAR (const struct ccase *c, struct expression *e, const struct variable *v)
{
  struct substring s = alloc_string (e, var_get_width (v));
  memcpy (s.string, case_str (c, v), var_get_width (v));
  return s;
}

static inline double 
eval_OP_SUB (double a, double b)
{
  return a - b;
}

static inline double 
eval_OP_VEC_ELEM_NUM (double idx, const struct vector *v, const struct ccase *c)
{
  if (idx >= 1 && idx <= vector_get_var_cnt (v)) 
    {
      const struct variable *var = vector_get_var (v, (size_t) idx - 1);
      double value = case_num (c, var);
      return !var_is_num_missing (var, value, MV_USER) ? value : SYSMIS; 
    }
  else
    {
      if (idx == SYSMIS)
        msg (SE, _("SYSMIS is not a valid index value for vector "
                   "%s.  The result will be set to SYSMIS."),
             vector_get_name (v));
      else
        msg (SE, _("%g is not a valid index value for vector %s.  "
                   "The result will be set to SYSMIS."),
             idx, vector_get_name (v));
      return SYSMIS;
    }
}

static inline struct substring 
eval_OP_VEC_ELEM_STR (double idx, struct expression *e, const struct vector *v, const struct ccase *c)
{
  if (idx >= 1 && idx <= vector_get_var_cnt (v))
    {
      struct variable *var = vector_get_var (v, (size_t) idx - 1);
      return copy_string (e, CHAR_CAST_BUG (char *, case_str (c, var)),
                          var_get_width (var));
    }
  else
    {
      if (idx == SYSMIS)
        msg (SE, _("SYSMIS is not a valid index value for vector "
                   "%s.  The result will be set to the empty string."),
             vector_get_name (v));
      else
        msg (SE, _("%g is not a valid index value for vector %s.  "
                   "The result will be set to the empty string."),
             idx, vector_get_name (v));
      return empty_string;
    }
}


/*
   Local Variables:
   mode: c
   buffer-read-only: t
   End:
*/
