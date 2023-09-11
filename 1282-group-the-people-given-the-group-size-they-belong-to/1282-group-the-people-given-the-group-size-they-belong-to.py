class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        ans=[]
        group_map=collections.defaultdict(list)
        for i,group_size in enumerate(groupSizes):
            group_map[group_size].append(i)

        return [ids[i:i+k]
        for k,ids in group_map.items()
        for i in range(0,len(ids),k)] 