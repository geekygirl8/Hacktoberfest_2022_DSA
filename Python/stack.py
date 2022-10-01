
# Creation of stack happens here
def createStack():
    stack = []
    return stack


# If your length of stack is 0 then stack is empty
def isEmpty(stack):
    return len(stack) == 0


# Just use append to add item
def push(stack, item):
    stack.append(item)
    print(item + " pushed to stack ")


# Pop removes the top most / last element in stack/list
def pop(stack):
    if (isEmpty(stack)):
        return str(-maxsize - 1)  # return minus infinite

    return stack.pop()


# Get the topmost element in the stack
def peek(stack):
    if (isEmpty(stack)):
        return str(-maxsize - 1)  # return minus infinite
    return stack[len(stack) - 1]


# Driver program
stack = createStack()
push(stack, str(5))
push(stack, str(10))
push(stack, str(15))
push(stack, str(20))
print(pop(stack) + " popped from stack")
