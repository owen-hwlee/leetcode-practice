object Solution {
    def reverseWords(s: String): String = {
        s.split(" ")
         .map(x => x.reverse)
         .mkString(" ")
    }
}