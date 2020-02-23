from datetime import date

class Solution:
    def daysBetweenDates(self, date1: str, date2: str) -> int:
                   
        year, mon, day = map(int, date1.split('-'))
        year1, mon1, day1 = map(int, date2.split('-'))
        d0 = date(year, mon, day)
        d1 = date(year1, mon1, day1)
        
        delta = abs(d0 - d1)
        
        
        return delta.days;
    
