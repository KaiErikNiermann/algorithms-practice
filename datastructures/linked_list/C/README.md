## Notes
- My implementations use a `head` and `tail` node, you can omit the `tail` node but I think in practice its just useful to have (unless you are using sentinel nodes), so I decided to keep it.
- You can see quite a few variations on how to modify the pointers correctly when inserting/deleting a node, I felt like the approach here is simple yet still understandable but I would always say look at different variations and see what is the most intuitive for you.
- The single and doubly linked code a very similar, the only difference is the added code to properly rearrange the `prev` pointer, I thought it made sense to still have both versions to show the difference and how one develops on the other.
- To fully understand sentinels I recommend Introduction to Algorithms by Cormen et al. (CLRS) and the wikipedia article on [doubly linked lists](https://en.wikipedia.org/wiki/Doubly_linked_list#Sentinel_nodes).