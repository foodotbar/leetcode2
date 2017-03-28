/*bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    int i,j;
    if(k<=0)
        return 0;
    for(i=0;i<numsSize;i++){
        for(j=i+1;j<numsSize;j++){
            if((nums[i]==nums[j])&&(i+k>=j))
                return 1;
        }
    }
    return 0;
}*/
#define SIZE 42947

struct hash_table
{
  int key;
  int value;
};

struct hash_map
{
  struct hash_table **ht;
};

struct hash_table* hash_table_int(int key, int value)
{
  struct hash_table *h = (struct hash_table*)malloc(sizeof(struct hash_table*));
  h->key =key;
  h->value = value;
  return h;
}

int get_value(struct hash_map *hm, int key)
{
 int hash = (abs(key % SIZE));
 if (hash<0) {
   return -1;
 }
 while (hm->ht[hash] != NULL && hm->ht[hash]->key != key) {
   hash = (hash+1)%SIZE;
 }
 if (hm->ht[hash] == NULL) {
   return -1;
 } else {
   return hm->ht[hash]->value;
 }
}

void put_value(struct hash_map *hm, int key, int value)
{
  int hash = (abs(key % SIZE));
  if (hash<0) {
   return;
  }
  while (hm->ht[hash] != NULL && hm->ht[hash]->key != key) {
    hash = (hash+1)%SIZE;
  }
  if (hm->ht[hash] != NULL) {
    free(hm->ht[hash]);
  }
  hm->ht[hash] = hash_table_int(key, value);
}

void free_hm(struct hash_map *hm)
{
  for (int i=0; i< SIZE; i++) {
    if (hm->ht[i] != NULL) {
      free(hm->ht[i]);
    }
  }
  free(hm);
}

struct hash_map * new_hm()
{
  struct hash_map *hm = (struct hash_map*)malloc(sizeof(struct hash_map*));
  hm->ht = (struct hash_table**)malloc(sizeof(struct hash_table*)*SIZE);
  for (int i=0; i<SIZE; i++) {
    hm->ht[i] = NULL;
  }
  return hm;
}

bool containsNearbyDuplicate(int *nums, int numsSize, int k)
{
    if (k==0) {
        return false;
    }
    struct hash_map *hm = new_hm();
    for (int i=0; i<numsSize; i++) {
        int val = get_value(hm, nums[i]);
        if (val == -1) {
            put_value(hm, nums[i], i);
        }
        if (val != -1) {
            if (abs(val - i) <=k) {
                return true;
            }
            put_value(hm, nums[i], i);
        }
    }
    return false;
}
