#include "headers/loan_calc.h"

/* ANNUITY FORMULAS */

long double get_monthly_payment_annuity(long double loan_amount,
                                        long double interest_rate,
                                        double term) {
  long double monthly_interest = interest_rate / 12 / 100;
  long double annuity_coefficient = monthly_interest *
                                    powl(1 + monthly_interest, term) /
                                    (powl(1 + monthly_interest, term) - 1);
  long double annuity = annuity_coefficient * loan_amount;

  return annuity;
}

long double get_total_payment_annuity(long double annuity, double term) {
  return annuity * term;
}

/* DIFFERENTIATED FORMULAS */

long double get_monthly_payment_diff(long double total_payment, double term) {
  // average
  return total_payment / term;
}

long double get_total_payment_diff(long double loan_amount, double term,
                                   long double interest_rate) {
  long double non_diff_monthly_payment = loan_amount / term;
  long double total_payment = 0;

  for (int month = 0; month < term; month++) {
    long double left_to_pay = loan_amount - (non_diff_monthly_payment * month);
    long double interest_payment = left_to_pay * (interest_rate / 100 / 12);
    long double monthly_payment = non_diff_monthly_payment + interest_payment;
    total_payment += monthly_payment;
  }

  return total_payment;
}

/* OVERPAYMENT ON CREDIT */
long double get_overpayment_on_credit(long double loan_amount,
                                      long double total_payment) {
  return total_payment - loan_amount;
}

/* YEARS -> MONTHS CONVERTER */
double convert_years_to_months(double years) { return years * 12; }
