C Payroll with overtime
      program payroll
      real rate, hours, pay
      read (*,*) rate, hours
      if (hours>40) then
          pay=40*rate+(hours-40)*1.5*rate
      else
          pay=hours*rate
      END IF
          print *,"rate=", rate
          print *, "hours=", hours
          print *,"pay=",pay
      end
