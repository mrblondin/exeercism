const WEEKS_LAST_DATE = { "first": 7, "second": 14, "third": 21, "fourth": 28,
  "teenth": 19, }

const DAY_OF_WEEK = { "Monday": 1, "Tuesday": 2, "Wednesday": 3, "Thursday": 4,
                      "Friday": 5, "Saturday": 6, "Sunday": 0}

const DAYS_IN_WEEK = 7;

const days_in_month = (month, year) => {
  if ([1, 3, 5, 7, 8, 10, 12].includes(month)) return 31;
  if ([4, 6, 9, 11].includes(month)) return 30;
  if (month === 2) return is_leap_year(year) ? 29 : 28;
}

const is_leap_year = (year) => !(year % 400) || (!(year % 4) && year % 100)

const last_date_of_week = (week, month, year) =>
  week === "last" ? days_in_month(month, year) : WEEKS_LAST_DATE[week];

// global week day identifier
const weekday = (day, month, year) =>
  (day += month < 3 ? year-- : year - 2, Math.floor(23 * month/9) + day 
   + 4 + Math.floor(year/4)- Math.floor(year/100) + Math.floor(year/400)) % 7;


export const meetup = (year, month, week, day_of_week) => {

  const last_week_date = last_date_of_week(week, month, year);
  const last_week_day = weekday(last_week_date, month, year);
  const week_day = DAY_OF_WEEK[day_of_week];
  console.log(last_week_date, last_week_day, week_day);
  const day = last_week_date - (last_week_day - week_day + DAYS_IN_WEEK) 
    % DAYS_IN_WEEK
  console.log(year, month - 1, day)

  return new Date(year, month - 1, day)
};
