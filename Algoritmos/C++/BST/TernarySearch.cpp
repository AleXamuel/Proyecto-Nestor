//Not the topic but why not
while(l+2<r) {
    int m1=(l+l+r)/3;
    int m2=(l+r+r)/3;
    if(PA[m1]+PB[c-m1]>PA[m2]+PB[c-m2])
        r=m2;
    else
        l=m1;
}
ll ans=0;
For(i,l,r+1)
    ans=max(ans,PA[i]+PB[c-i]);
