long long inv(long long t, long long p)
{
	return t == 1 ? 1 : (p - p / t) * inv(p % t, p) % p;
}
