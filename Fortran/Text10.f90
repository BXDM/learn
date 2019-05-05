
!  VF0944.f90 
!
!  FUNCTIONS:
!	VF0944      - Entry point of console application.
!
!	Example of displaying 'Hello World' at execution time.
!

!****************************************************************************
!
!  PROGRAM: VF0944
!
!  PURPOSE:  Entry point for 'Hello World' sample console application.
!
!****************************************************************************

	program VF0944
	implicit none

	integer a, b, c
	a= 8
	b= 6
	c= a*b

	print *, 'Hello World, a, b, c= ', a, b, c
	end program VF0944