ar* longestPalindrome(char* s) {
        if (strlen(s) < 2)
            return s;
        int len = strlen(s), max_left = 0, max_len = 1, left, right;
        for (int start = 0; start < len && len - start > max_len / 2;) {
            left = right = start;
            while (right < len - 1 && s[right + 1] == s[right])
                ++right;
            start = right + 1;
            while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1]) {
                ++right;
                --left;
            }
            if (max_len < right - left + 1) {
                max_left = left;
                max_len = right - left + 1;
            }
        }
        char* ans=(char*)calloc(max_len+1,sizeof(char));
        int j=0;
        for(j=0;j<max_len;j++)
            ans[j]=s[max_left+j];
        ans[j]='\0';
        return ans;
}

/*
char* longestPalindrome(char* s) {
	int len = strlen(s);
	if (len < 2) return s;
	int left = 0, right = 0;
	for (int i = 0; len - 1 - i > (right - left + 1) / 2;) {
		int l = i; int r = i;
		while (r < len - 1 && s[r + 1] == s[r]) r++; //找到所有的重复字母
		i = r + 1;
		while (l > 0 && r < len - 1 && s[l - 1] == s[r + 1]) {  //以重复字母片段的左右向两边扩散
			r++;
			l--;
		}
		if (r - l > right - left) { // 筛选最长的回文
			left = l;
			right = r;
		}
	}
	s[right + 1] = '\0'; 
	return s + left;
}
/*
