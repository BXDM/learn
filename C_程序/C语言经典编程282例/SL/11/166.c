swap(int *p1, int *p2)
{
    int temp;
    temp =  *p1;
    *p1 =  *p2;
    *p2 = temp;
}

exchange(int *pt1, int *pt2, int *pt3)
{
    if (*pt1 <  *pt2)
        swap(pt1, pt2);
    if (*pt1 <  *pt3)
        swap(pt1, pt3);
    if (*pt2 <  *pt3)
        swap(pt2, pt3);
}

main()
{
    int a, b, c,  *q1,  *q2,  *q3;
    puts("Please input three key numbers you want to rank:");
    scanf("%d,%d,%d", &a, &b, &c);
    q1 = &a;
    q2 = &b;
    q3 = &c;
    exchange(q1, q2, q3);
    printf("\n%d,%d,%d\n", a, b, c);
    puts("\n Press any key to quit...");
    getch();
}
