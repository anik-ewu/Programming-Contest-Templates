long long combination(long long n, long long r){
      if (r > n)return 0;
      if (n - r < r)r = n - r;
      n %= mod;
      long long ans = 1;
      for (int i = 0; i < r; i++){
            ans = (ans * (n - i)) % mod;
            ans = (ans * inv[i + 1]) % mod;
      }
      return ans;
}
