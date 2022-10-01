//Name: Nikita
// Github id: geekygirl8

class Solution:
    def numDecodings(self, s: str) -> int:
        # Use mapping to define the set
        mapping = set()
    
# Now we define the range and start map

        for i in range(1, 27):
            mapping.add(str(i))
        return self.break_string(s, 0, mapping, {})

    # After getting the requried set

    # Now for thhe next step we have to first seperate the data into each components so we add break_string function

    def break_string(self, s, count, mapping, mem):

    # After breaking the set (ie.,array) into its seperate indidvisuals , it should start decoding with the given grouped map into letters 

        if s == "":
            return count + 1

        ans = 0
        if s not in mem:
            for i in range(len(s)):

                if s[:i+1] in mapping:
                    ans += self.break_string(s[i+1:], count, mapping, mem)

            mem[s] = ans

        return mem[s]
