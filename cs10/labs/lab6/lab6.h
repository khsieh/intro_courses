/** @fn string monthConvert(string);
 * @author Brian Linard
 * @brief helper function for dateConvert, a date format parser
 * @param monthNumber string representing number from 1 to 12
 * @return name of the corresponding month
 * @warning there is an intentional bug in the function code!
 */
  
string monthConvert(string monthNumber)
{
  if (monthNumber == "1")
    return "January";
  if (monthNumber == "2")
    return "February";
  if (monthNumber == "3")
    return "March";
  if (monthNumber == "4")
    return "April";
  if (monthNumber == "5")
    return "May";
  if (monthNumber == "6")
    return "June";
  if (monthNumber == "7")
    return "July";
  if (monthNumber == "8")
    return "August";
  if (monthNumber == "9")
    return "September";
  if (monthNumber == "10")
    return "October";
  if (monthNumber == "11")
    return "November";
  if (monthNumber == "12")
    return "December";
  else
    return "Invalid Month";
}
