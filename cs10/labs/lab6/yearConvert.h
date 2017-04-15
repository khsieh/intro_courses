string yearConvert(string yearNum)
{
    string p = "20";
    
    if(yearNum.size() == 4)
    return yearNum;
    if(yearNum.size() == 2)
    return p + yearNum;
    else
    return "invalid year number";
}
