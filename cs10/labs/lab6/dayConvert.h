string dayConvert(string dayNumber)
{
    if(dayNumber == "1")
    return "st";
    if(dayNumber == "2")
    return "nd";
    if(dayNumber == "3")
    return "rd";
    if(dayNumber == "21")
    return "st";
    if(dayNumber == "22")
    return "nd";
    if(dayNumber == "23")
    return "rd";
    if(dayNumber == "31")
    return "st";
    else
    return "th";
}
