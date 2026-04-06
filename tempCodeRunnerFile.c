case 7:
        printf("Enter index you want to delete: ");
        scanf("%d", &index);
        printf("Linked list before deletion\n");
        trevLinkedList(head);
        head = deleteAtIndex(head, index);
        printf("\nLinked list after deletion\n");
        trevLinkedList(head);
        break;