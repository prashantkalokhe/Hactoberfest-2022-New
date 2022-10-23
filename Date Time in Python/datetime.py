from datetime import date
from datetime import time
from datetime import datetime
from datetime import timedelta


def main1():
    today = date.today()
    print("Today's date is ", today)
    print("date components: ", today.day, today.month, today.year)
    print("today's weekday is: ", today.weekday())
    days = ["mon", "tue", "wed", "thu", "fri", "sat", "sun"]
    print("what is the name of the weekday: ", days[today.weekday()])


def main2():
    today = datetime.now()
    print("the current date and time is: ", today)
    t = datetime.time(datetime.now())
    print("the current time is: ", t)


def main3():
    now = datetime.now()
    print(now.strftime("the current year is: %Y"))

    # %y/%Y: Year; %a/%A: weekday; %b/%B: month; %d: day of month
    print(now.strftime("%a, %d %B, %y"))

    # %c: local date and time; %x: local's date; %X: local's time
    print(now.strftime("local's date and time is: %c"))
    print(now.strftime("local's date: %x"))
    print(now.strftime("local's time is: %X"))

    # Time Formatting
    # %I/%H: 12/24 Hour time; %M: minute; %S: second; %p: local's AM/PM
    print(now.strftime("current time: %I:%M:%S %p"))
    print(now.strftime("24 Hour time: %H:%M"))


def main4():
    print(timedelta(days=366, hours=18, minutes=45, seconds=78))
    now = datetime.now()
    print("today is: " + str(now))
    print("one year from now it will be: " + str(now + timedelta(days=365)))
    print("in 2 days and 3 weeks, it will be: " +
          str(now + timedelta(days=2, weeks=3)))

    t = datetime.now() - timedelta(weeks=1)
    s = t.strftime("%A %B %d, %Y")
    print("one week ago it was: ", s)
    today = date.today()
    april_fool = date(today.year, 4, 1)

    if april_fool < today:
        print("April fool day is went by %d days ago" % (today-april_fool).days)
        april_fool = april_fool.replace(year=today.year + 1)
        ti_to_april_fool = april_fool - today
        print("it's just %d days until april fool day" % ti_to_april_fool.days)




main1()
main2()
main3()
main4()
