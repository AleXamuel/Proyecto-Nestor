int mod(int a, int b) {
    if (b < 0)
        b *= -1;
    return (a % b + b) % b;
}
