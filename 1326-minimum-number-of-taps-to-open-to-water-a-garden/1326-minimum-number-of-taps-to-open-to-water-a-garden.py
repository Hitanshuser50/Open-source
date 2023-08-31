class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        # Create an array to store the maximum right boundary that each tap can reach
        max_reach = [0] * (n + 1)
        
        # Populate the max_reach array based on the ranges of each tap
        for i, r in enumerate(ranges):
            if r == 0:
                continue
            left_boundary = max(0, i - r)
            right_boundary = min(n, i + r)
            max_reach[left_boundary] = max(max_reach[left_boundary], right_boundary)
        
        # Initialize variables to keep track of the watering progress
        end, far_can_reach, taps_used = 0, 0, 0
        
        # Iterate through the garden points and water them using the taps
        for i, reach in enumerate(max_reach):
            if i > end:
                # If the current position can't be reached, return -1
                if far_can_reach <= end:
                    return -1
                # Update the end to the farthest reachable point and increment taps_used
                end, taps_used = far_can_reach, taps_used + 1
            # Update the farthest point we can currently reach
            far_can_reach = max(far_can_reach, reach)
        
        # Return the total taps_used + 1 if end is less than n, indicating extra tap needed
        return taps_used + (end < n)