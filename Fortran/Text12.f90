program circle
real  :: r, area
!This program reads a real number r and prints
!the area of a circle with radius r
read (*,*) r
area = 3.14159*r*r
write (*,*)' Area = ',area
stop
END program circle